#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "action.h"
#include "name.h"

using namespace::std;

class File : public Node
{
    public:
        friend class Action;
        friend class Name;
        friend class Find;

        File(const char *path): Node(path)
        {
         
        }

        // string find(string nodeName) const
        // {
        //   if (nodeName==this->name()) return name();
        //   else return ("");
        // }

        string accept(Action *visitor)
        {
            return visitor->visitFile(this);
        }

        string classType()
        {
            return "File";
        }

};
#endif
