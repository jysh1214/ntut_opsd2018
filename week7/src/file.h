#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include "info_content_visitor.h"
#include "find_visitor.h"
#include "find_link_visitor.h"
#include "find_node_by_pathname_visitor.h"


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

  void accept(NodeVisitor *fileVisitor)
  {
    fileVisitor->visitFile(this);
  }

};

#endif
