// generated by Fast Light User Interface Designer (fluid) version 1.0104

#include "uninst.h"

Fl_Window *UninstallWindow=(Fl_Window *)0;

static void cb_UninstallWindow(Fl_Window*, void*) {
  if (CancelButton->active())
  exit(0);
}

Fl_Wizard *Wizard=(Fl_Wizard *)0;

Fl_Group *WelcomePane=(Fl_Group *)0;

Fl_Box *WelcomeImage=(Fl_Box *)0;

Fl_Group *SoftwarePane=(Fl_Group *)0;

Fl_Check_Browser *SoftwareList=(Fl_Check_Browser *)0;

Fl_Box *SoftwareSize=(Fl_Box *)0;

Fl_Button *RemoveAllButton=(Fl_Button *)0;

static void cb_RemoveAllButton(Fl_Button*, void*) {
  SoftwareList->check_all();
list_cb(0,0);
}

Fl_Button *RemoveNoneButton=(Fl_Button *)0;

static void cb_RemoveNoneButton(Fl_Button*, void*) {
  SoftwareList->check_none();
list_cb(0,0);
}

Fl_Group *ConfirmPane=(Fl_Group *)0;

Fl_Browser *ConfirmList=(Fl_Browser *)0;

Fl_Group *RemovePane=(Fl_Group *)0;

Fl_Progress *RemovePercent=(Fl_Progress *)0;

Fl_Browser *RemoveLog=(Fl_Browser *)0;

Fl_Button *PrevButton=(Fl_Button *)0;

static void cb_PrevButton(Fl_Button*, void*) {
  Wizard->prev();
}

Fl_Button *NextButton=(Fl_Button *)0;

Fl_Button *CancelButton=(Fl_Button *)0;

static void cb_CancelButton(Fl_Button*, void*) {
  exit(0);
}

Fl_Window* make_window() {
  Fl_Window* w;
  { Fl_Window* o = UninstallWindow = new Fl_Window(580, 345, "ESP Software Removal Wizard");
    w = o;
    o->callback((Fl_Callback*)cb_UninstallWindow);
    { Fl_Wizard* o = Wizard = new Fl_Wizard(10, 10, 560, 290);
      { Fl_Group* o = WelcomePane = new Fl_Group(10, 10, 560, 290);
        o->hide();
        { Fl_Box* o = new Fl_Box(20, 20, 540, 25, "Welcome to the Software Removal Wizard");
          o->labelfont(1);
          o->labelsize(18);
          o->labelcolor(4);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = WelcomeImage = new Fl_Box(20, 50, 540, 180);
          o->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = new Fl_Box(20, 235, 540, 55, "This wizard will remove the software you select from your system.\n\nTo selec\
t software for removal, please click on the \"Next\" button below.");
          o->align(133|FL_ALIGN_INSIDE);
        }
        o->end();
      }
      { Fl_Group* o = SoftwarePane = new Fl_Group(10, 10, 560, 290);
        o->hide();
        { Fl_Box* o = new Fl_Box(20, 20, 540, 25, "Software Selection");
          o->labelfont(1);
          o->labelsize(18);
          o->labelcolor(4);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = new Fl_Box(20, 55, 540, 35, "Please select the software you would like to remove and click on the \"Next\"\
 button below.");
          o->align(133|FL_ALIGN_INSIDE);
        }
        { Fl_Check_Browser* o = SoftwareList = new Fl_Check_Browser(20, 120, 540, 135, " Available Software:");
          o->type(3);
          o->box(FL_DOWN_BOX);
          o->selection_color(7);
          o->callback((Fl_Callback*)list_cb);
          o->align(FL_ALIGN_TOP_LEFT);
          o->when(3);
        }
        { Fl_Box* o = SoftwareSize = new Fl_Box(20, 265, 265, 25, "0k marked for removal.");
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Button* o = RemoveAllButton = new Fl_Button(295, 265, 120, 25, "Remove All");
          o->callback((Fl_Callback*)cb_RemoveAllButton);
        }
        { Fl_Button* o = RemoveNoneButton = new Fl_Button(425, 265, 135, 25, "Remove None");
          o->callback((Fl_Callback*)cb_RemoveNoneButton);
        }
        o->end();
      }
      { Fl_Group* o = ConfirmPane = new Fl_Group(10, 10, 560, 290);
        o->hide();
        { Fl_Box* o = new Fl_Box(20, 20, 540, 25, "Confirm Removal");
          o->labelfont(1);
          o->labelsize(18);
          o->labelcolor(4);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Box* o = new Fl_Box(20, 55, 540, 50, "You have selected the software below for removal. Click on the \"Next\" butto\
n to start the software removal or the \"Back\" button to change your selectio\
ns.");
          o->align(133|FL_ALIGN_INSIDE);
        }
        ConfirmList = new Fl_Browser(20, 110, 540, 180);
        o->end();
      }
      { Fl_Group* o = RemovePane = new Fl_Group(10, 10, 560, 290);
        { Fl_Box* o = new Fl_Box(20, 20, 540, 25, "Removing Software...");
          o->labelfont(1);
          o->labelsize(18);
          o->labelcolor(4);
          o->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
        }
        { Fl_Progress* o = RemovePercent = new Fl_Progress(20, 75, 540, 15, "Progress Label...");
          o->selection_color(63);
          o->labelfont(2);
          o->align(FL_ALIGN_TOP_LEFT);
        }
        RemoveLog = new Fl_Browser(20, 100, 540, 190);
        o->end();
      }
      o->end();
    }
    { Fl_Button* o = PrevButton = new Fl_Button(280, 310, 90, 25, "@-2< Back");
      o->callback((Fl_Callback*)cb_PrevButton);
    }
    { Fl_Button* o = NextButton = new Fl_Button(380, 310, 90, 25, "Next @-2>");
      o->callback((Fl_Callback*)next_cb);
    }
    { Fl_Button* o = CancelButton = new Fl_Button(480, 310, 90, 25, "Cancel");
      o->callback((Fl_Callback*)cb_CancelButton);
    }
    o->end();
  }
  return w;
}
