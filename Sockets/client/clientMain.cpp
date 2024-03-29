/***************************************************************
 * Name:      clientMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-21
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "clientMain.h"
#include "../motor_protocol.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(clientFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <iostream>

using namespace std;

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

//(*IdInit(clientFrame)
const long clientFrame::ID_START_BUTTON = wxNewId();
const long clientFrame::ID_STOP_BUTTON = wxNewId();
const long clientFrame::ID_ROTATE_L_BUTTON = wxNewId();
const long clientFrame::ID_ROTATE_R_BUTTON = wxNewId();
const long clientFrame::ID_SPEED_BUTTON = wxNewId();
const long clientFrame::ID_SPINCTRL1 = wxNewId();
const long clientFrame::ID_STATICTEXT2 = wxNewId();
const long clientFrame::idMenuQuit = wxNewId();
const long clientFrame::idMenuAbout = wxNewId();
const long clientFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(clientFrame,wxFrame)
    //(*EventTable(clientFrame)
    //*)
    EVT_SOCKET(wxID_ANY,clientFrame::OnSocketEvent)
END_EVENT_TABLE()

clientFrame::clientFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(clientFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxStaticText* StaticText1;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StartButton = new wxButton(this, ID_START_BUTTON, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_START_BUTTON"));
    BoxSizer2->Add(StartButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StopButton = new wxButton(this, ID_STOP_BUTTON, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_STOP_BUTTON"));
    BoxSizer2->Add(StopButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    RotateLButton = new wxButton(this, ID_ROTATE_L_BUTTON, _("Rotate Left"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ROTATE_L_BUTTON"));
    BoxSizer3->Add(RotateLButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RotateRButton = new wxButton(this, ID_ROTATE_R_BUTTON, _("Rotate Right"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ROTATE_R_BUTTON"));
    BoxSizer3->Add(RotateRButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    SetSpeedButton = new wxButton(this, ID_SPEED_BUTTON, _("Set Speed"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SPEED_BUTTON"));
    BoxSizer4->Add(SetSpeedButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpeedSpinCtrl = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 0, _T("ID_SPINCTRL1"));
    SpeedSpinCtrl->SetValue(_T("0"));
    BoxSizer4->Add(SpeedSpinCtrl, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, wxID_ANY, _("Response"), wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ResponseText = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(ResponseText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

    Connect(ID_START_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&clientFrame::OnButtonClick);
    Connect(ID_STOP_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&clientFrame::OnButtonClick);
    Connect(ID_ROTATE_L_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&clientFrame::OnButtonClick);
    Connect(ID_ROTATE_R_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&clientFrame::OnButtonClick);
    Connect(ID_SPEED_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&clientFrame::OnButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&clientFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&clientFrame::OnAbout);
    //*)

    request = nullptr;

    m_client = new wxSocketClient();
    m_client->SetEventHandler(*this,wxID_ANY);
    m_client->SetNotify(wxSOCKET_CONNECTION_FLAG |
                        wxSOCKET_INPUT_FLAG|
                        wxSOCKET_LOST_FLAG);

    m_client->Notify(true);
    m_addr = wxIPV4address();
    m_addr.Service(3000);
}

clientFrame::~clientFrame()
{
    //(*Destroy(clientFrame)
    //*)
    m_client->Destroy();
}

void clientFrame::OnQuit(wxCommandEvent&)
{
    Close();
}

void clientFrame::OnAbout(wxCommandEvent&)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void clientFrame::OnSocketEvent(wxSocketEvent& event)
{
    wxSocketBase* socket = event.GetSocket();

    std::cout << "Socket event" << event.GetSocketEvent() << std::endl;

    switch(event.GetSocketEvent())
    {
        case wxSOCKET_CONNECTION:
            {
            socket->Write(request,request->size);
            break;
            }

        case wxSOCKET_INPUT:
            {
            struct MotorResponse *response = new struct MotorResponse;
            socket->Read(response,sizeof(response));
            socket->Close();

            wxString label;
            if(response->type == RESPONSE_OK)
                label << "Ok";
            else if(response->type == RESPONSE_INFO)
                label << "Info";
            else if(response->type == RESPONSE_ERROR)
                label << "Error";
            else
                label << "Unknown";

            ResponseText->SetLabel(label);
            break;
            }

        case wxSOCKET_OUTPUT:
        case wxSOCKET_LOST:
            break;
    }
}

void clientFrame::OnButtonClick(wxCommandEvent& event)
{
    delete request;
    request = new struct MotorRequest;

    int id = event.GetId();

    if(id == ID_START_BUTTON) {
        request->command = START_CMD;
        request->size = 2;

    } else if (id == ID_STOP_BUTTON) {
        request->command = STOP_CMD;
        request->size = 2;

    } else if (id == ID_ROTATE_L_BUTTON) {
        request->command = ROTATE_CMD;
        request->attributes[0] = ROTATE_LEFT;
        request->size = 3;

    } else if (id == ID_ROTATE_R_BUTTON) {
        request->command = ROTATE_CMD;
        request->attributes[0] = ROTATE_RIGHT;
        request->size = 3;

    } else if (id == ID_SPEED_BUTTON) {
        int speed = SpeedSpinCtrl->GetValue();

        request->command = SPEED_CMD;
        request->attributes[0] = (uint8_t)speed;
        request->size = 3;
    }

    m_client->Connect(m_addr,false);
}
