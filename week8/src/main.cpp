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

    _defaultRoot = wxGetApp().argv[1];
    NodeBuilder nb;

    char * c_defaultRoot = &_defaultRoot[0u];

    nb.build(c_defaultRoot);

    Frame * frame = new Frame(wxT("***Tree Test***"), nb.getRoot());
    frame->Show(true);
    return true;
}
