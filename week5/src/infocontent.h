#ifndef INFO_CONTENT_VISITOR_H
#define INFO_CONTENT_VISITOR_H

#include "node_visitor.h"

class Node;
class File;
class Folder;

using namespace::std;

class InfoContentVisitor: public NodeVisitor
{
    public:
        InfoContentVisitor();
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
