#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

#include <string>

class File;
class Folder;

using namespace::std;

class NodeVisitor
{
    public:
        virtual void visitFile(File *file) = 0;
        virtual void visitFolder(Folder *folder) = 0;

        //virtual string getName();
        virtual string findResult(){return "";}
        virtual int getContentSize(){return 0;}
};
#endif
