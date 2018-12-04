#ifndef LINK_H
#define LINK_H

#include "node.h"
#include "node_visitor.h"
#include "info_content_visitor.h"
#include "find_visitor.h"
#include "find_link_visitor.h"
#include "find_node_by_pathname_visitor.h"

class Link : public Node
{
  public:
    Link(const char *path, Node *node = nullptr) : Node(path)
    {
        this->addLink(node);
        struct stat st;
        if (lstat(path, &st) == 0)
        {
            if (!S_ISLNK(st.st_mode))
            {
                throw std::string("Node type error.");
            }
        }
    }

    void accept(NodeVisitor * nodeVisitor)
    {
        nodeVisitor->visitLink(this);
    }

    void addLink(Node *node)
    {
        _source = node;
    }

    Node *getSource()
    {
        return _source;
    }

  private:
    Node *_source;
};

#endif
