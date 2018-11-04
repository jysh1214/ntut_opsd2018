#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H

#include <string>
#include <map>
#include "node_visitor.h"

class Node;
class File;
class Folder;

using namespace::std;

class FindVisitor: public NodeVisitor
{
    public:
        FindVisitor(string name);
        void visitFile(File *file);
        void visitFolder(Folder *folder);
        void findName(map<string, Node *>& answer, Node *node);

        string findResult()
        {
            return _answer;
        }

    private:
        string _nodeName;
        string _answer;
};
#endif
