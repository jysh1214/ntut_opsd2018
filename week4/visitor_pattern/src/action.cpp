#include "action.h"
#include "file.h"
#include "folder.h"

Action::Action(){}
void Action::visitFile(File *file){}
void Action::visitFolder(Folder *folder){}

string Action::getName() const {}
string Action::findResult() const {};
int Action::getContentSize() const {};
