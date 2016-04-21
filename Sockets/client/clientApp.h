/***************************************************************
 * Name:      clientApp.h
 * Purpose:   Defines Application Class
 * Author:    Marcos Mirabent (mmira031@fiu.edu)
 * Created:   2016-04-21
 * Copyright: Marcos Mirabent ()
 * License:
 **************************************************************/

#ifndef CLIENTAPP_H
#define CLIENTAPP_H

#include <wx/app.h>

class clientApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // CLIENTAPP_H
