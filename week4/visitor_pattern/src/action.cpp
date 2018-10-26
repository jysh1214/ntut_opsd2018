#include "action.h"
#include "node.h"
#include "file.h"
#include "folder.h"

Action::Action(){}
void Action::visitFile(File *file){}
void Action::visitFolder(Folder *folder){}

string Action::getName(){}
string Action::findResult(){};
int Action::getContentSize(){};
