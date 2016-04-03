/***************************************************************
 * Name:      url_searchApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-03
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#include "url_searchApp.h"

//(*AppHeaders
#include "url_searchMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(url_searchApp)

bool url_searchApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	url_searchFrame* Frame = new url_searchFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
