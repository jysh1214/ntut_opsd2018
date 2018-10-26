#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "node.h"
#include "action.h"
#include "name.h"

using namespace std;

class Folder: public Node
{
    public:
        friend class Action;
        friend class Name;
        friend class Find;
        friend class InfoContent;

        Folder(const char *path): Node(path)
        {
            
        }

        void add(Node *node)
        {
            _children.push_back(node);
        }

        int numberOfChildren() const
        {
            return _children.size();
        }

        void accept(Action *visitor)
        {
            visitor->visitFolder(this);
        }

        vector<Node *> getChildren() const
        {
            return _children;
        }

        string classType() const
        {
            return "Folder";
        }
        
    private:
        vector<Node *> _children;
};
#endif
