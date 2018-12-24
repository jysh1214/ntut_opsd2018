#ifndef FILE_H
#define FILE_H

#include "node.h"

class File : public Node
{
public:
    File(const char *path) : Node(path)
    {
        struct stat st;
        if (lstat(path, &st) == 0)
        {
            if (!S_ISREG(st.st_mode))
            {
                throw std::string("Node type error.");
            }
        }
    }

    virtual ~File(){}
};

#endif
