// generated by Fast Light User Interface Designer (fluid) version 1.0100

#ifndef ListEditor_h
#define ListEditor_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "epm.h"
#include <FL/Fl_Preferences.H>
#include <FL/Fl_Menu_Bar.H>
#include "ListManager.h"
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_File_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>

class ListEditor {
  static ListEditor *first_;
  static char history_[10][1024];
  static Fl_Preferences prefs_;
  dist_t *dist_;
  char filename_[1024];
  char icontitle_[1024];
  int margins_[7];
  int modified_;
  ListEditor *next_;
  char title_[1024];
  static void build_cb(ListEditor *le);
  int check_save();
  static void close_cb(ListEditor *le);
  static void copy_cb(ListEditor *le);
  static void cut_cb(ListEditor *le);
  static void delete_cb(ListEditor *le);
  static void file_settings_cb(ListEditor *le, int save);
  static void help_cb(ListEditor *le, const char *html);
  static void list_cb(ListEditor *le);
  static void margins_cb(ListEditor *le);
  void modified(int m);
  static void new_cb(ListEditor *le);
  static void open_cb(ListEditor *le);
  static void open_history_cb(ListEditor *le, const char *listfile);
  static void paste_cb(ListEditor *le);
  static void project_settings_cb(ListEditor *le);
  static void quit_cb(ListEditor *le);
  static void save_cb(ListEditor *le);
  static void save_as_cb(ListEditor *le);
  void set_title();
  void update_history(const char *listfile);
  void update_list();
  void update_margins();
public:
  ListEditor(const char *listfile);
private:
  Fl_Double_Window *window;
  inline void cb_window_i(Fl_Double_Window*, void*);
  static void cb_window(Fl_Double_Window*, void*);
  Fl_Menu_Bar *menubar;
  static Fl_Menu_Item menu_menubar[];
  inline void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  inline void cb_Open_i(Fl_Menu_*, void*);
  static void cb_Open(Fl_Menu_*, void*);
  static Fl_Menu_Item *history_items;
  inline void cb_history_items_i(Fl_Menu_*, void*);
  static void cb_history_items(Fl_Menu_*, void*);
  inline void cb_filename_i(Fl_Menu_*, void*);
  static void cb_filename(Fl_Menu_*, void*);
  inline void cb_filename1_i(Fl_Menu_*, void*);
  static void cb_filename1(Fl_Menu_*, void*);
  inline void cb_filename2_i(Fl_Menu_*, void*);
  static void cb_filename2(Fl_Menu_*, void*);
  inline void cb_filename3_i(Fl_Menu_*, void*);
  static void cb_filename3(Fl_Menu_*, void*);
  inline void cb_filename4_i(Fl_Menu_*, void*);
  static void cb_filename4(Fl_Menu_*, void*);
  inline void cb_filename5_i(Fl_Menu_*, void*);
  static void cb_filename5(Fl_Menu_*, void*);
  inline void cb_filename6_i(Fl_Menu_*, void*);
  static void cb_filename6(Fl_Menu_*, void*);
  inline void cb_filename7_i(Fl_Menu_*, void*);
  static void cb_filename7(Fl_Menu_*, void*);
  inline void cb_filename8_i(Fl_Menu_*, void*);
  static void cb_filename8(Fl_Menu_*, void*);
  inline void cb_Close_i(Fl_Menu_*, void*);
  static void cb_Close(Fl_Menu_*, void*);
  inline void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
  inline void cb_Save1_i(Fl_Menu_*, void*);
  static void cb_Save1(Fl_Menu_*, void*);
  inline void cb_Build_i(Fl_Menu_*, void*);
  static void cb_Build(Fl_Menu_*, void*);
  inline void cb_Quit_i(Fl_Menu_*, void*);
  static void cb_Quit(Fl_Menu_*, void*);
  inline void cb_Copy_i(Fl_Menu_*, void*);
  static void cb_Copy(Fl_Menu_*, void*);
  inline void cb_Cu_i(Fl_Menu_*, void*);
  static void cb_Cu(Fl_Menu_*, void*);
  inline void cb_Delete_i(Fl_Menu_*, void*);
  static void cb_Delete(Fl_Menu_*, void*);
  inline void cb_Paste_i(Fl_Menu_*, void*);
  static void cb_Paste(Fl_Menu_*, void*);
  inline void cb_Select_i(Fl_Menu_*, void*);
  static void cb_Select(Fl_Menu_*, void*);
  inline void cb_Select1_i(Fl_Menu_*, void*);
  static void cb_Select1(Fl_Menu_*, void*);
  inline void cb_Add_i(Fl_Menu_*, void*);
  static void cb_Add(Fl_Menu_*, void*);
  static Fl_Menu_Item *file_settings_item;
  inline void cb_file_settings_item_i(Fl_Menu_*, void*);
  static void cb_file_settings_item(Fl_Menu_*, void*);
  inline void cb_P_i(Fl_Menu_*, void*);
  static void cb_P(Fl_Menu_*, void*);
  inline void cb_Contents_i(Fl_Menu_*, void*);
  static void cb_Contents(Fl_Menu_*, void*);
  inline void cb_Introduction_i(Fl_Menu_*, void*);
  static void cb_Introduction(Fl_Menu_*, void*);
  inline void cb_Basic_i(Fl_Menu_*, void*);
  static void cb_Basic(Fl_Menu_*, void*);
  inline void cb_Advanced_i(Fl_Menu_*, void*);
  static void cb_Advanced(Fl_Menu_*, void*);
  inline void cb_Version_i(Fl_Menu_*, void*);
  static void cb_Version(Fl_Menu_*, void*);
  ListManager *margin_manager;
  inline void cb_margin_manager_i(ListManager*, void*);
  static void cb_margin_manager(ListManager*, void*);
  Fl_Menu_Button *margin_menu;
  static Fl_Menu_Item menu_margin_menu[];
  static Fl_Menu_Item *margin_items;
  inline void cb_margin_items_i(Fl_Menu_*, void*);
  static void cb_margin_items(Fl_Menu_*, void*);
  inline void cb_User_i(Fl_Menu_*, void*);
  static void cb_User(Fl_Menu_*, void*);
  inline void cb_Group_i(Fl_Menu_*, void*);
  static void cb_Group(Fl_Menu_*, void*);
  inline void cb_Destination_i(Fl_Menu_*, void*);
  static void cb_Destination(Fl_Menu_*, void*);
  inline void cb_Source_i(Fl_Menu_*, void*);
  static void cb_Source(Fl_Menu_*, void*);
  inline void cb_Package_i(Fl_Menu_*, void*);
  static void cb_Package(Fl_Menu_*, void*);
  Fl_File_Browser *list;
  inline void cb_list_i(Fl_File_Browser*, void*);
  static void cb_list(Fl_File_Browser*, void*);
  Fl_Double_Window *file_window;
  Fl_Choice *type_chooser;
  inline void cb_type_chooser_i(Fl_Choice*, void*);
  static void cb_type_chooser(Fl_Choice*, void*);
  static Fl_Menu_Item menu_type_chooser[];
  inline void cb_Regular_i(Fl_Menu_*, void*);
  static void cb_Regular(Fl_Menu_*, void*);
  inline void cb_Configuration_i(Fl_Menu_*, void*);
  static void cb_Configuration(Fl_Menu_*, void*);
  inline void cb_Manpage_i(Fl_Menu_*, void*);
  static void cb_Manpage(Fl_Menu_*, void*);
  inline void cb_Init_i(Fl_Menu_*, void*);
  static void cb_Init(Fl_Menu_*, void*);
  inline void cb_Directory_i(Fl_Menu_*, void*);
  static void cb_Directory(Fl_Menu_*, void*);
  inline void cb_Symbolic_i(Fl_Menu_*, void*);
  static void cb_Symbolic(Fl_Menu_*, void*);
  inline void cb_Removed_i(Fl_Menu_*, void*);
  static void cb_Removed(Fl_Menu_*, void*);
  Fl_Check_Button *upgrade_button;
  inline void cb_upgrade_button_i(Fl_Check_Button*, void*);
  static void cb_upgrade_button(Fl_Check_Button*, void*);
  Fl_Group *perm_group;
  inline void cb_perm_group_i(Fl_Group*, void*);
  static void cb_perm_group(Fl_Group*, void*);
  inline void cb_Permissions_i(Fl_Box*, void*);
  static void cb_Permissions(Fl_Box*, void*);
  Fl_Light_Button *user_read_button;
  inline void cb_user_read_button_i(Fl_Light_Button*, void*);
  static void cb_user_read_button(Fl_Light_Button*, void*);
  Fl_Light_Button *user_write_button;
  inline void cb_user_write_button_i(Fl_Light_Button*, void*);
  static void cb_user_write_button(Fl_Light_Button*, void*);
  Fl_Light_Button *user_exec_button;
  inline void cb_user_exec_button_i(Fl_Light_Button*, void*);
  static void cb_user_exec_button(Fl_Light_Button*, void*);
  Fl_Light_Button *user_set_button;
  inline void cb_user_set_button_i(Fl_Light_Button*, void*);
  static void cb_user_set_button(Fl_Light_Button*, void*);
  inline void cb_User1_i(Fl_Box*, void*);
  static void cb_User1(Fl_Box*, void*);
  Fl_Light_Button *group_read_button;
  inline void cb_group_read_button_i(Fl_Light_Button*, void*);
  static void cb_group_read_button(Fl_Light_Button*, void*);
  Fl_Light_Button *group_write_button;
  inline void cb_group_write_button_i(Fl_Light_Button*, void*);
  static void cb_group_write_button(Fl_Light_Button*, void*);
  Fl_Light_Button *group_exec_button;
  inline void cb_group_exec_button_i(Fl_Light_Button*, void*);
  static void cb_group_exec_button(Fl_Light_Button*, void*);
  Fl_Light_Button *group_set_button;
  inline void cb_group_set_button_i(Fl_Light_Button*, void*);
  static void cb_group_set_button(Fl_Light_Button*, void*);
  inline void cb_Group1_i(Fl_Box*, void*);
  static void cb_Group1(Fl_Box*, void*);
  Fl_Light_Button *other_read_button;
  inline void cb_other_read_button_i(Fl_Light_Button*, void*);
  static void cb_other_read_button(Fl_Light_Button*, void*);
  Fl_Light_Button *other_write_button;
  inline void cb_other_write_button_i(Fl_Light_Button*, void*);
  static void cb_other_write_button(Fl_Light_Button*, void*);
  Fl_Light_Button *other_exec_button;
  inline void cb_other_exec_button_i(Fl_Light_Button*, void*);
  static void cb_other_exec_button(Fl_Light_Button*, void*);
  Fl_Light_Button *other_temp_button;
  inline void cb_other_temp_button_i(Fl_Light_Button*, void*);
  static void cb_other_temp_button(Fl_Light_Button*, void*);
  inline void cb_Other_i(Fl_Box*, void*);
  static void cb_Other(Fl_Box*, void*);
  Fl_Input *user_field;
  inline void cb_user_field_i(Fl_Input*, void*);
  static void cb_user_field(Fl_Input*, void*);
  Fl_Input *group_field;
  inline void cb_group_field_i(Fl_Input*, void*);
  static void cb_group_field(Fl_Input*, void*);
  Fl_Input *src_path_field;
  inline void cb_src_path_field_i(Fl_Input*, void*);
  static void cb_src_path_field(Fl_Input*, void*);
  Fl_Input *dst_path_field;
  inline void cb_dst_path_field_i(Fl_Input*, void*);
  static void cb_dst_path_field(Fl_Input*, void*);
  Fl_Input *subpackage_field;
  inline void cb_subpackage_field_i(Fl_Input*, void*);
  static void cb_subpackage_field(Fl_Input*, void*);
  Fl_Return_Button *file_ok_button;
  inline void cb_file_ok_button_i(Fl_Return_Button*, void*);
  static void cb_file_ok_button(Fl_Return_Button*, void*);
  Fl_Button *file_cancel_button;
  inline void cb_file_cancel_button_i(Fl_Button*, void*);
  static void cb_file_cancel_button(Fl_Button*, void*);
public:
  ~ListEditor();
  void hide();
  int modified();
  int open(const char *listfile);
  int save(const char *listfile);
  int save();
  void show();
  int shown();
};
#endif