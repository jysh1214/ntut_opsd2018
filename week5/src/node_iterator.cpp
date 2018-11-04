#include "node.h"
#include "file.h"
#include "folder.h"
#include "node_visitor.h"

NodeVisitor::NodeVisitor(){}
void NodeVisitor::visitFile(File *file){}
void NodeVisitor::visitFolder(Folder *folder){}

string NodeVisitor::getName(){}
string NodeVisitor::findResult(){};
int NodeVisitor::getContentSize(){};
