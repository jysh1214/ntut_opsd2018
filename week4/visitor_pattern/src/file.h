#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "action.h"
#include "name.h"

using namespace::std;

class File : public Node
{
    public:
        File(const char *path): Node(path)
        {
         
        }

        void accept(Action *visitor)
        {
            visitor->visitFile(this);
        }
};
#endif
