/***************************************************************
 * Name:      clientApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-21
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "clientApp.h"

//(*AppHeaders
#include "clientMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(clientApp);

bool clientApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	clientFrame* Frame = new clientFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
