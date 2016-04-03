/***************************************************************
 * Name:      url_searchMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-03
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "url_searchMain.h"
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <wx/sstream.h>
#include <wx/protocol/http.h>
#include <iostream>

//(*InternalHeaders(url_searchFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(url_searchFrame)
const long url_searchFrame::ID_TEXTCTRL1 = wxNewId();
const long url_searchFrame::ID_FILEPICKERCTRL1 = wxNewId();
const long url_searchFrame::ID_FILEPICKERCTRL2 = wxNewId();
const long url_searchFrame::ID_BUTTON1 = wxNewId();
const long url_searchFrame::idMenuQuit = wxNewId();
const long url_searchFrame::idMenuAbout = wxNewId();
const long url_searchFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(url_searchFrame,wxFrame)
    //(*EventTable(url_searchFrame)
    //*)
END_EVENT_TABLE()

url_searchFrame::url_searchFrame(wxWindow* parent,wxWindowID)
{
    //(*Initialize(url_searchFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxStaticText* StaticText1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxStaticText* StaticText2;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    OutputTextCtrl = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(OutputTextCtrl, 1, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer1 = new wxFlexGridSizer(3, 2, 0, 0);
    StaticText1 = new wxStaticText(this, wxID_ANY, _("URL File"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    URLFilePickerCtrl = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, _T("*.txt"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
    FlexGridSizer1->Add(URLFilePickerCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, wxID_ANY, _("Search Terms File"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SearchFilePickerCtrl = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL2, wxEmptyString, wxEmptyString, _T("*.txt"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN, wxDefaultValidator, _T("ID_FILEPICKERCTRL2"));
    FlexGridSizer1->Add(SearchFilePickerCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StartButton = new wxButton(this, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(StartButton, 0, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_TOP, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&url_searchFrame::OnStartButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&url_searchFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&url_searchFrame::OnAbout);
    //*)
}

url_searchFrame::~url_searchFrame()
{
    //(*Destroy(url_searchFrame)
    //*)
}

void url_searchFrame::OnQuit(wxCommandEvent&)
{
    Close();
}

void url_searchFrame::OnAbout(wxCommandEvent&)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void url_searchFrame::OnStartButtonClick(wxCommandEvent&)
{
    std::vector<wxURL> urls;
    std::vector<std::string> terms;

    wxHTTP http;

    wxString urls_file = URLFilePickerCtrl->GetPath();
    wxString terms_file = SearchFilePickerCtrl->GetPath();

    if(urls_file.empty() || terms_file.empty())
        return; // TODO: Notify the user that they need to select a file

    readURLsFromFile(urls_file,urls);
    readSearchTermsFromFile(terms_file,terms);

    for(wxURL& url : urls) {

        // If the url is missing a path, check the root path
        wxString path;
        if(url.GetPath().IsEmpty()) {
            path = "/";
        } else {
            path = url.GetPath();
        }

        // Create the connection
        while(!http.Connect(url.GetServer()))
            wxSleep(500);

        // Actually perform the get request and load the response into get
        wxInputStream* stream = http.GetInputStream(url.GetPath());

        if(http.GetError() == wxPROTO_NOERR) {

            wxString body;
            wxStringOutputStream out_stream(&body);
            stream->Read(out_stream);

            for(std::string& str : terms) {
                std::cout << "Searching for: " << str << std::endl;
            }
        }
    }
}

void url_searchFrame::readURLsFromFile(const wxString& path, std::vector<wxURL>& urls)
{
    wxTextFile file(path);
    wxString str;

    if(!file.Open())
        return; // Something terrible has happened

    for(str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine()) {
            wxURL url(str);
            if(url.IsOk())
                urls.push_back(url);
    }

    file.Close();
}

void url_searchFrame::readSearchTermsFromFile(const wxString& path, std::vector<std::string>& terms)
{
    wxTextFile file(path);
    wxString str;

    if(!file.Open())
        return; // Something terrible has happened

    for(str = file.GetFirstLine(); !file.Eof(); str = file.GetNextLine()) {
            terms.push_back(str.ToStdString());
    }

    file.Close();
}

int url_searchFrame::countSubstringsInString(const std::string& sub, const std::string& str)
{

    return 0;
}
