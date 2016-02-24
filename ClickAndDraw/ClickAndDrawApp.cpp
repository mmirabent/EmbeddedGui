/***************************************************************
 * Name:      ClickAndDrawApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-02-23
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "ClickAndDrawApp.h"

//(*AppHeaders
#include "ClickAndDrawMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ClickAndDrawApp);

bool ClickAndDrawApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ClickAndDrawFrame* Frame = new ClickAndDrawFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
