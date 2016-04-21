/***************************************************************
 * Name:      clientMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-21
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H

//(*Headers(clientFrame)
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class clientFrame: public wxFrame
{
    public:

        clientFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~clientFrame();

    private:

        //(*Handlers(clientFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(clientFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(clientFrame)
        wxButton* StopButton;
        wxStatusBar* StatusBar1;
        wxButton* SetSpeedButton;
        wxButton* StartButton;
        wxSpinCtrl* SpeedSpinCtrl;
        wxButton* RotateRButton;
        wxStaticText* ResponseText;
        wxButton* RotateLButton;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CLIENTMAIN_H
