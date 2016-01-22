#include "wx/wx.h"

// Declare the application class
class MyApp : public wxApp {
    public:
        virtual bool OnInit();
};

class MyFrame : public wxFrame {
    public:
        // Constructor
        MyFrame(const wxString& title);

        // Event Handler
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

    private:
        // This class handles events
        DECLARE_EVENT_TABLE()
};

DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    // Create frame
    MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));

    // Show it
    frame->Show(true);

    // Start the event loop
    return true;
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxString msg;
    msg.Printf(wxT("Hello and welcome to %s"),wxVERSION_STRING);

    wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event) {
    // Destroy the frame!
    Close();
}

#include "mondrian.xpm"

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
    // Set the frame icon
    SetIcon(wxIcon(mondrian_xpm));

    // Create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // The "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;

    helpMenu->Append(wxID_ABOUT,wxT("&About...\tF1"),wxT("Show about dialog"));
    fileMenu->Append(wxID_EXIT,wxT("E&xit\tAlt-X"),wxT("Quit this program"));

    // Now append the menubars
    wxMenuBar *menuBar = new wxMenuBar();

    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));

    // Aaaaaand attach the menu bar
    SetMenuBar(menuBar);

    // Create a status bar just for fun
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to wxWidgets!"));
}

