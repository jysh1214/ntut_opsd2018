#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"

using namespace::std;

class File : public Node
{
    public:
        class NullIterator: public NodeIterator
        {
            public:
                NullIterator(){}
                void first(){}
                Node * currentItem(){}
                void next(){}

                bool isDone()
                {
                    return true;
                }
        };

        File(const char *path): Node(path)
        {
         
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
