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

        string visitFile(File *file);
        string visitFolder(Folder *folder);
        void findName(vector<Node *>& answer, Node *node);

    private:
        string _nodeName;
};

#endif
