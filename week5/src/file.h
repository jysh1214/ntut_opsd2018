#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "null_iterator.h"

using namespace::std;

class File : public Node
{
    public:
        File(const char *path): Node(path)
        {
         
        }

        string name() const
        {
            string nodeName;
            string tempStr = this->getPath();
            nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));
            return nodeName;
        }

        void accept(NodeVisitor *visitor)
        {
            visitor->visitFile(this);
        }

        NodeIterator * createIterator()
        {
            return new NullIterator();
        }
};
#endif
