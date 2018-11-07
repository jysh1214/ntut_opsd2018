#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <map>
#include <string>
#include "node_visitor.h"
#include "node_iterator.h"

using namespace::std;

class Node
{
    public:
        Node(const char * path): _path(path)
        {
            lstat(_path, &_st);
            if (lstat(_path, &_st) == -1) throw string("No such file or directory.");
        }

        int size() const
        {
            return _st.st_size;
        }

        virtual void add(Node *node)
        {
            throw string("unable to add\n");
        }

        virtual int numberOfChildren() const
        {
            throw string("number of children: not applicable\n");
        }

        string getPath() const
        {
            return _path;
        }

        string name() const
        {
            string nodeName;
            string tempStr = this->getPath();
            nodeName = tempStr.substr(tempStr.find_last_of("/")+1, tempStr.length()-tempStr.find_last_of("/"));
            return nodeName;
        }

        virtual NodeIterator * createIterator()
        {
            return nullptr;
        }

        virtual void accept(NodeVisitor *visitor)
        {
            // FindVisitor
            // InfoContentVisitor
        }

        virtual map<string, Node *> getChildren() const
        {
            throw string("get children: not applicable\n");
        }

  private:
        const char * _path;
        struct stat _st;
};
#endif
