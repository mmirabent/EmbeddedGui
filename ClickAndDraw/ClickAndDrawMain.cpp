/***************************************************************
 * Name:      ClickAndDrawMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-02-23
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "ClickAndDrawMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <wx/dcclient.h>
#include <wx/dc.h>
#include <wx/panel.h>
#include <wx/clrpicker.h>
#include <wx/choice.h>
#include <wx/window.h>

//(*InternalHeaders(ClickAndDrawFrame)
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

//(*IdInit(ClickAndDrawFrame)
const long ClickAndDrawFrame::ID_PANEL1 = wxNewId();
const long ClickAndDrawFrame::ID_COLOURPICKERCTRL1 = wxNewId();
const long ClickAndDrawFrame::ID_CHOICE1 = wxNewId();
const long ClickAndDrawFrame::idMenuQuit = wxNewId();
const long ClickAndDrawFrame::idMenuAbout = wxNewId();
const long ClickAndDrawFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ClickAndDrawFrame,wxFrame)
    //(*EventTable(ClickAndDrawFrame)
    //*)
END_EVENT_TABLE()

ClickAndDrawFrame::ClickAndDrawFrame(wxWindow* parent,wxWindowID id)
{
    // Initialize variables
    drawPoints = new std::vector<wxPoint>();
    mode = ColorSelectMode;

    //(*Initialize(ClickAndDrawFrame)
    wxMenuItem* MenuItem2;
    wxBoxSizer* VerticalSizer;
    wxMenuItem* MenuItem1;
    wxBoxSizer* HorizontalSizer;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    HorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
    DrawPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    DrawPanel->SetMinSize(wxSize(400,500));
    DrawPanel->SetBackgroundColour(wxColour(255,255,255));
    HorizontalSizer->Add(DrawPanel, 1, wxALL|wxEXPAND, 5);
    VerticalSizer = new wxBoxSizer(wxVERTICAL);
    ColorPicker = new wxColourPickerCtrl(this, ID_COLOURPICKERCTRL1, wxColour(0,0,0), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_COLOURPICKERCTRL1"));
    VerticalSizer->Add(ColorPicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ThicknessPicker = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    VerticalSizer->Add(ThicknessPicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    HorizontalSizer->Add(VerticalSizer, 0, wxALL|wxALIGN_TOP, 5);
    SetSizer(HorizontalSizer);
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
    HorizontalSizer->Fit(this);
    HorizontalSizer->SetSizeHints(this);

    DrawPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelPaint,0,this);
    DrawPanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelLeftDown,0,this);
    DrawPanel->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&ClickAndDrawFrame::OnDrawPanelLeftDoubleClick,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClickAndDrawFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&ClickAndDrawFrame::OnAbout);
    //*)
}

ClickAndDrawFrame::~ClickAndDrawFrame()
{
    //(*Destroy(ClickAndDrawFrame)
    //*)
}

void ClickAndDrawFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ClickAndDrawFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ClickAndDrawFrame::OnDrawPanelLeftDown(wxMouseEvent& event)
{
    // If we are in draw mode, ignore single clicks
    if(mode == DrawMode) {
        event.Skip(); // Documentation recommended
        return;
    }

    // If we were in color select mode, change the mode to clickmode
    if(mode == ColorSelectMode) {
        changeMode(ClickMode);
    }

    // Get the mouse position and push it onto the end of the vector
    wxPoint position = event.GetPosition();
    drawPoints->push_back(position);

    // Recommended by the wxMouseEvent documentation
    event.Skip();
}

void ClickAndDrawFrame::OnDrawPanelLeftDoubleClick(wxMouseEvent& event)
{

    switch(mode) {

    case ClickMode:
        changeMode(DrawMode);
        break;

    case DrawMode:
        changeMode(ColorSelectMode);
        break;

    case ColorSelectMode:
        // Do nothing
        break;
    }
}

// This event makes sure to paint the panel again whenever it's needed and we are in the DrawMode
void ClickAndDrawFrame::OnDrawPanelPaint(wxPaintEvent& event)
{
    if(mode == DrawMode) {
        wxPaintDC dc(DrawPanel);
        dc.SetPen(*wxBLUE_PEN);
        dc.DrawLines(drawPoints->size(), drawPoints->data());
    }
}

void ClickAndDrawFrame::changeMode(Modes NewMode)
{
    mode = NewMode;

    switch(NewMode) {
    case ColorSelectMode:
        // Enable color selection controls
        drawPoints->clear();
        ColorPicker->Enable();
        ThicknessPicker->Enable();
        DrawPanel->Refresh();
        break;

    case ClickMode:
        // Disable color selection controls
        ColorPicker->Disable();
        ThicknessPicker->Disable();
        break;

    case DrawMode:
        // Set the pen and force a refresh
        pen = new wxPen(*wxBLUE);
        DrawPanel->Refresh();
        break;
    }
}
