/*
 * "$Id: bsd.c,v 1.5 2002/06/04 19:30:33 mike Exp $"
 *
 *   FreeBSD package gateway for the ESP Package Manager (EPM).
 *
 *   Copyright 1999-2002 by Easy Software Products.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 * Contents:
 *
 *   make_bsd() - Make a FreeBSD software distribution package.
 */

/*
 * Include necessary headers...
 */

#include "epm.h"


/*
 * 'make_bsd()' - Make a FreeBSD software distribution package.
 */

int					/* O - 0 = success, 1 = fail */
make_bsd(const char     *prodname,	/* I - Product short name */
         const char     *directory,	/* I - Directory for distribution files */
         const char     *platname,	/* I - Platform name */
         dist_t         *dist,		/* I - Distribution information */
	 struct utsname *platform)	/* I - Platform information */
{
  int		i;			/* Looping var */
  FILE		*fp;			/* Spec file */
  char		name[1024];		/* Full product name */
  char		commentname[1024];	/* pkg comment filename */
  char		descrname[1024];	/* pkg descr filename */
  char		plistname[1024];	/* pkg plist filename */
  char		filename[1024];		/* Destination filename */
  char		*old_user,		/* Old owner UID */
		*old_group;		/* Old group ID */
  int		old_mode;		/* Old permissions */
  file_t	*file;			/* Current distribution file */
  command_t	*c;			/* Current command */
  depend_t	*d;			/* Current dependency */
  struct passwd	*pwd;			/* Pointer to user record */
  struct group	*grp;			/* Pointer to group record */
  char		current[1024];		/* Current directory */


  REF(platform);

  if (Verbosity)
    puts("Creating FreeBSD pkg distribution...");

  getcwd(current, sizeof(current));

  if (dist->relnumber)
  {
    if (platname[0])
      snprintf(name, sizeof(name), "%s-%s-%d-%s", prodname, dist->version, dist->relnumber,
              platname);
    else
      snprintf(name, sizeof(name), "%s-%s-%d", prodname, dist->version, dist->relnumber);
  }
  else if (platname[0])
    snprintf(name, sizeof(name), "%s-%s-%s", prodname, dist->version, platname);
  else
    snprintf(name, sizeof(name), "%s-%s", prodname, dist->version);

 /*
  * Write the descr file for pkg...
  */

  if (Verbosity)
    puts("Creating descr file...");

  snprintf(descrname, sizeof(descrname), "%s/%s.descr", directory, prodname);

  if ((fp = fopen(descrname, "w")) == NULL)
  {
    fprintf(stderr, "epm: Unable to create descr file \"%s\" - %s\n", descrname,
            strerror(errno));
    return (1);
  }

  fprintf(fp, "%s\n", dist->product);

  fclose(fp);

 /*
  * Write the comment file for pkg...
  */

  if (Verbosity)
    puts("Creating comment file...");

  snprintf(commentname, sizeof(commentname), "%s/%s.comment", directory, prodname);

  if ((fp = fopen(commentname, "w")) == NULL)
  {
    fprintf(stderr, "epm: Unable to create comment file \"%s\" - %s\n", commentname,
            strerror(errno));
    return (1);
  }

  fprintf(fp, "Summary: %s\n", dist->product);
  fprintf(fp, "Name: %s\n", prodname);
  fprintf(fp, "Version: %s\n", dist->version);
  fprintf(fp, "Release: %d\n", dist->relnumber);
  fprintf(fp, "Copyright: %s\n", dist->copyright);
  fprintf(fp, "Packager: %s\n", dist->packager);
  fprintf(fp, "Vendor: %s\n", dist->vendor);
  fprintf(fp, "BuildRoot: %s/%s/buildroot\n", current, directory);
  fputs("Group: Applications\n", fp);

  fputs("Description:\n\n", fp);
  for (i = 0; i < dist->num_descriptions; i ++)
    fprintf(fp, "%s\n", dist->descriptions[i]);

  fclose(fp);

 /*
  * Write the plist file for pkg...
  */

  if (Verbosity)
    puts("Creating plist file...");

  snprintf(plistname, sizeof(plistname), "%s/%s.plist", directory, prodname);

  if ((fp = fopen(plistname, "w")) == NULL)
  {
    fprintf(stderr, "epm: Unable to create plist file \"%s\" - %s\n", plistname,
            strerror(errno));
    return (1);
  }

  fprintf(fp, "@srcdir %s/%s/buildroot\n", current, directory);
  fputs("@option preserve\n", fp);

  for (i = dist->num_depends, d = dist->depends; i > 0; i --, d ++)
  {
    if (d->type == DEPEND_REQUIRES)
      fprintf(fp, "@pkgdep %s", d->product);
    else
#ifdef __FreeBSD__
     /*
      * FreeBSD doesn't have @pkgcfl command...
      */
      fprintf(fp, "@comment conflicts with: %s", d->product);
#else
      fprintf(fp, "@pkgcfl %s", d->product);
#endif /* __FreeBSD */
    if (d->vernumber[0] == 0)
    {
      if (d->vernumber[1] < INT_MAX)
        fprintf(fp, " <= %s\n", d->version[1]);
      else
        putc('\n', fp);
    }
    else
      fprintf(fp, " >= %s, <= %s\n", d->version[0], d->version[1]);
  }

  for (i = dist->num_commands, c = dist->commands; i > 0; i --, c ++)
    switch (c->type)
    {
      case COMMAND_PRE_INSTALL :
          fputs("WARNING: Package contains pre-install commands which are not supported\n"
	        "         by the BSD packager.\n", stderr);
          break;
      case COMMAND_POST_INSTALL :
          fprintf(fp, "@exec %s\n", c->command);
	  break;
      case COMMAND_PRE_REMOVE :
          fprintf(fp, "@unexec %s\n", c->command);
	  break;
      case COMMAND_POST_REMOVE :
          fputs("WARNING: Package contains post-removal commands which are not supported\n"
	        "         by the BSD packager.\n", stderr);
          break;
    }

  for (i = dist->num_files, file = dist->files, old_mode = 0, old_user = "",
           old_group = "";
       i > 0;
       i --, file ++)
  {
    if (file->mode != old_mode)
      fprintf(fp, "@mode %04o\n", old_mode = file->mode);
    if (strcmp(file->user, old_user))
      fprintf(fp, "@owner %s\n", old_user = file->user);
    if (strcmp(file->group, old_group))
      fprintf(fp, "@group %s\n", old_group = file->group);

    switch (tolower(file->type))
    {
      case 'i' :
          fprintf(fp, "usr/local/etc/rc.d/%s.sh\n", file->dst);
          break;
      case 'c' :
      case 'f' :
      case 'l' :
          fprintf(fp, "%s\n", file->dst + 1);
          break;
      case 'd' :
          fprintf(fp, "%s\n@dirrm %s\n", file->dst + 1, file->dst + 1);
          break;
    }
  }

  fclose(fp);

 /*
  * Copy the files over...
  */

  if (Verbosity)
    puts("Copying temporary distribution files...");

  for (i = dist->num_files, file = dist->files; i > 0; i --, file ++)
  {
   /*
    * Find the username and groupname IDs...
    */

    pwd = getpwnam(file->user);
    grp = getgrnam(file->group);

    endpwent();
    endgrent();

   /*
    * Copy the file or make the directory or make the symlink as needed...
    */

    switch (tolower(file->type))
    {
      case 'c' :
      case 'f' :
          snprintf(filename, sizeof(filename), "%s/buildroot%s", directory, file->dst);

	  if (Verbosity > 1)
	    printf("%s -> %s...\n", file->src, filename);

	  if (copy_file(filename, file->src, file->mode, pwd ? pwd->pw_uid : 0,
			grp ? grp->gr_gid : 0))
	    return (1);
          break;
      case 'i' :
          snprintf(filename, sizeof(filename), "%s/buildroot/etc/rc.d/%s", directory,
	          file->dst);

	  if (Verbosity > 1)
	    printf("%s -> %s...\n", file->src, filename);

	  if (copy_file(filename, file->src, file->mode, pwd ? pwd->pw_uid : 0,
			grp ? grp->gr_gid : 0))
	    return (1);
          break;
      case 'd' :
          snprintf(filename, sizeof(filename), "%s/buildroot%s", directory, file->dst);

	  if (Verbosity > 1)
	    printf("Directory %s...\n", filename);

          make_directory(filename, file->mode, pwd ? pwd->pw_uid : 0,
			 grp ? grp->gr_gid : 0);
          break;
      case 'l' :
          snprintf(filename, sizeof(filename), "%s/buildroot%s", directory, file->dst);

	  if (Verbosity > 1)
	    printf("%s -> %s...\n", file->src, filename);

          make_link(filename, file->src);
          break;
    }
  }

 /*
  * Build the distribution...
  */

  if (Verbosity)
    puts("Building FreeBSD pkg binary distribution...");

  if (run_command(NULL, "pkg_create -p / -s %s -c %s -d %s -f %s %s",
                  current, commentname, descrname, plistname, prodname))
    return (1);

 /*
  * Remove temporary files...
  */

  if (!KeepFiles)
  {
    if (Verbosity)
      puts("Removing temporary distribution files...");

    run_command(NULL, "/bin/rm -rf %s/buildroot", directory);

    unlink(plistname);
    unlink(commentname);
    unlink(descrname);
  }

  return (0);
}


/*
 * End of "$Id: bsd.c,v 1.5 2002/06/04 19:30:33 mike Exp $".
 */
