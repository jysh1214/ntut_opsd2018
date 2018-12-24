#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <string>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();

private:
    std::string _defaultRoot;
};

#endif
