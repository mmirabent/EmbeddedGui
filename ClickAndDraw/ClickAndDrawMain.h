/***************************************************************
 * Name:      ClickAndDrawMain.h
 * Purpose:   Defines Application Frame
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-02-23
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#ifndef CLICKANDDRAWMAIN_H
#define CLICKANDDRAWMAIN_H

#include <vector>

//(*Headers(ClickAndDrawFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/clrpicker.h>
#include <wx/choice.h>
//*)

class ClickAndDrawFrame: public wxFrame
{
    public:

        ClickAndDrawFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ClickAndDrawFrame();

    private:
        std::vector<wxPoint> *drawPoints;
        enum Modes {
            ColorSelectMode,
            ClickMode,
            DrawMode
        } mode;

        //(*Handlers(ClickAndDrawFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDrawPanelLeftDown(wxMouseEvent& event);
        void OnDrawPanelLeftDoubleClick(wxMouseEvent& event);
        void OnDrawPanelPaint(wxPaintEvent& event);
        //*)

        //(*Identifiers(ClickAndDrawFrame)
        static const long ID_PANEL1;
        static const long ID_COLOURPICKERCTRL1;
        static const long ID_CHOICE1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(ClickAndDrawFrame)
        wxStatusBar* StatusBar1;
        wxPanel* DrawPanel;
        wxColourPickerCtrl* ColourPickerCtrl1;
        wxChoice* Choice1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // CLICKANDDRAWMAIN_H
