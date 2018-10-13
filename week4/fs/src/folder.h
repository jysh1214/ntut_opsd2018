#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"

using namespace::std;

class Folder: public Node
{
    public:

        Folder(const char* path): Node(path)
        {

        }

        void add(Node *node)
        {
            _children.push_back(node);
        }

        int infoContent() const
        {
            int sum = 0;
            for (int i = 0; i < _children.size(); i++)
            {
                sum += _children[i]->infoContent();
            }
            return sum;
        }

        int numberOfChildren() const
        {
            return _children.size();
        }

    private:
        vector<Node *> _children;
};
#endif
