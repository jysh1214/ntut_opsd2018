#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link : public Node
{
public:
    Link(const char *path, Node *node = nullptr) : Node(path)
    {
        struct stat st;
        if (lstat(path, &st) == 0)
        {
            if (!S_ISLNK(st.st_mode))
            {
                throw std::string("Node type error.");
            }
        }
    }

    virtual ~Link(){}
};

#endif
