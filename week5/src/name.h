#ifndef NAME_H
#define NAME_H

#include "node_visitor.h"

class File;
class Folder;

using namespace::std;

class Name: public NodeVisitor
{
    public:
        Name();
        void visitFile(File *file);
        void visitFolder(Folder *folder);
       
        string getName()
        {
            return _name;
        }

    private:
        string _name;
};
#endif
