// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// https://docs.wxwidgets.org/3.0/overview_xrc.html
#include "wx/xrc/xmlres.h"              // XRC XML resources

#ifdef __WXMSW__ // for ccls
#include <wx/frame.h>
#include <wx/menu.h>
#endif

// @see https://github.com/wxWidgets/wxWidgets/blob/master/samples/xrc/xrcdemo.cpp
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// @see https://github.com/wxWidgets/wxWidgets/blob/master/samples/xrc/myframe.cpp
class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow *parent = (wxWindow *) nullptr);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};


// *INDENT-OFF*
// clang-format off
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(XRCID("m_hello"), MyFrame::OnHello)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
// clang-format on
// *INDENT-ON*


bool MyApp::OnInit()
{
    if (! wxApp::OnInit())
        return false;

    wxXmlResource::Get()->InitAllHandlers();
    if (! wxXmlResource::Get()->LoadAllFiles("rc"))
        return false;
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(wxWindow *parent)
{
    wxXmlResource::Get()->LoadFrame(this, parent, "MyFrame");
    GetSizer()->SetSizeHints(this);
}

void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
