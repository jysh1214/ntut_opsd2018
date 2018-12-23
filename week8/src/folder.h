#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include "node.h"

class Folder : public Node
{
public:
    Folder(const char *path) : Node(path)
    {
        struct stat st;
        if (lstat(path, &st) == 0)
        {
            if (!S_ISDIR(st.st_mode))
            {
                throw std::string("Node type error.");
            }
        }
    }

    virtual ~Folder(){}

    void add(Node *node)
    {
        _children.push_back(node);
    }

    std::vector<Node *> getChildren()
    {
        return _children;
    }

private:
    std::vector<Node *> _children;
};

#endif
