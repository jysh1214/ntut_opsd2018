#include "main.h"
#include "frame.h"
#include "node_builder.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    if(wxGetApp().argv < 1)
    {
        fprintf(stderr, "usage: ./bin/hw8 live_data\n");
        return 0;
    }

    default_root = wxGetApp().argv[1];
    NodeBuilder nb;
    nb.build(default_root.c_str());

    Frame * frame = new Frame(wxT("***Tree Test***"), nb.getRoot());
    frame->Show(true);
    return true;
}
