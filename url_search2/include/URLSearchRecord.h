#ifndef URLSEARCHRECORD_H
#define URLSEARCHRECORD_H

#include <wx/url.h>
#include <map>
#include <string>

class URLSearchRecord
{
    public:
        URLSearchRecord();
        URLSearchRecord(wxURL url);
        virtual ~URLSearchRecord();
        void addSearchResult(std::string term, int n);
        std::string toString();
        wxURL url;
        std::map<std::string, int> results;
};

#endif // URLSEARCHRECORD_H
