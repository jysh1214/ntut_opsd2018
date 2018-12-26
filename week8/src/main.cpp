#include <wx/app.h> 
#include "main.h"
#include "frame.h"
#include "node_builder.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    if (wxGetApp().argc < 2)
    {
        fprintf(stderr, "usage: ./bin/hw8 --path\n");
        return 0;
    }

    default_root = wxGetApp().argv[1];
    NodeBuilder nb;
    nb.build(default_root.c_str());
    
    Frame * frame = new Frame(wxT("***Tree Test***"), nb.getRoot());
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}
