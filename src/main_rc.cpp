// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx/xrc/xmlres.h"              // XRC XML resources

#ifdef __WXMSW__ // for ccls
#include <wx/frame.h>
#include <wx/menu.h>
#endif

class MyApp : public wxApp {
 public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
 public:
  MyFrame( wxWindow* parent = (wxWindow*) nullptr);

 private:
  void OnHello(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
  wxDECLARE_EVENT_TABLE();
};

enum {
  ID_Hello = 1
};

// clang-format off
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(ID_Hello, MyFrame::OnHello)
  EVT_MENU(wxID_EXIT, MyFrame::OnExit)
  EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
// clang-format on

bool MyApp::OnInit() {
  if (! wxApp::OnInit() )
    return false;

  wxXmlResource::Get()->InitAllHandlers();
  MyFrame* frame = new MyFrame();
  frame->Show(true);
  return true;
}

MyFrame::MyFrame(wxWindow* parent) {
  wxXmlResource::Get()->LoadFrame(this, parent, "main_frame");
  GetSizer()->SetSizeHints(this);
}

void MyFrame::OnExit(wxCommandEvent &event) {
  Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("This is a wxWidgets' Hello world sample",
               "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent &event) {
  wxLogMessage("Hello world from wxWidgets!");
}
