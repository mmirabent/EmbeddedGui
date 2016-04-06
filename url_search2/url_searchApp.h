/***************************************************************
 * Name:      url_searchApp.h
 * Purpose:   Defines Application Class
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-03
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#ifndef URL_SEARCHAPP_H
#define URL_SEARCHAPP_H

#include <wx/app.h>

class url_searchApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // URL_SEARCHAPP_H
