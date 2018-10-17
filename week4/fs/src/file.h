#ifndef FILE_H
#define FILE_H

#include "node.h"

using namespace::std;

class File : public Node
{
    public:
    File(const char *path): Node(path)
    {

    }

    string find(string nodeName) const
    {
      if (nodeName==this->name()) return name();
      else return ("");
    }

};
#endif
