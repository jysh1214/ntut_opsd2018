#ifndef INFOCONTENT_H
#define INFOCONTENT_H

#include "node_visitor.h"
#include "node_iterator.h"

class Node;
class File;
class Folder;

using namespace::std;

class InfoContent: public NodeVisitor
{
    public:
        InfoContent();
        void visitFile(File *file);
        void visitFolder(Folder *folder);

        int getContentSize()
        {
            return _size;
        }

    private:
        int _size;
};
#endif
