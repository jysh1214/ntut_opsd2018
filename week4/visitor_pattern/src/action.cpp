#include "action.h"
#include "node.h"
#include "file.h"
#include "folder.h"

Action::Action()
{

}
/* error: ‘virtual’ outside class declaration
You only need to specify it in the class definition (in the header file). 
After that, the compiler knows that it's virtual.
*/
string Action::visitFile(File *file)
{

}

string Action::visitFolder(Folder *folder)
{

}
