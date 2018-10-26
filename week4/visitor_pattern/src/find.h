#ifndef FIND_H
#define FIND_H

#include <string>
#include <vector>
#include "action.h"

class Node;
class File;
class Folder;

using namespace::std;

class Find: public Action
{
    public:
        Find(string nodeName);
        void visitFile(File *file);
        void visitFolder(Folder *folder);
        void findName(vector<Node *>& answer, Node *node);

        string findResult()
        {
            return _answer;
        }

    private:
        string _nodeName;
        string _answer;
};
#endif
