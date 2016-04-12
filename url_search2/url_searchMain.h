/***************************************************************
 * Name:      url_searchMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-03
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#ifndef URL_SEARCHMAIN_H
#define URL_SEARCHMAIN_H

#include "URLThread.h"
#include "URLSearchRecord.h"
#include <vector>
#include <string>
#include <wx/url.h>
#include <wx/timer.h>
#include <wx/msgqueue.h>

//(*Headers(url_searchFrame)
#include <wx/gauge.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class url_searchFrame: public wxFrame
{
    public:

        url_searchFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~url_searchFrame();

    private:

        void readURLsFromFile(const wxString& path,
                              std::vector<wxURL>& urls);
        void readSearchTermsFromFile(const wxString& path,
                                     std::vector<std::string>& urls);
        std::string* output;
        URLThread* thread;
        wxTimer* timer;
        std::vector<wxURL>* urls;
        std::vector<std::string>* terms;
        std::vector<URLThread*> threads;

        wxMessageQueue<URLSearchRecord>* results_mq;
        wxMessageQueue<wxURL>* url_mq;

        size_t url_size;
        size_t urls_done;

        void OnIdle(wxIdleEvent& event);

        void startThreads(size_t n);
        void stopThreads();

        bool threadsRunning;

        //(*Handlers(url_searchFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void OnStopButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(url_searchFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_FILEPICKERCTRL1;
        static const long ID_FILEPICKERCTRL2;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_GAUGE1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(url_searchFrame)
        wxTextCtrl* OutputTextCtrl;
        wxButton* StopButton;
        wxStatusBar* StatusBar1;
        wxFilePickerCtrl* URLFilePickerCtrl;
        wxFilePickerCtrl* SearchFilePickerCtrl;
        wxButton* StartButton;
        wxStaticText* StaticText3;
        wxSpinCtrl* ThreadSpinCtrl;
        wxGauge* ProgressGauge;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // URL_SEARCHMAIN_H
