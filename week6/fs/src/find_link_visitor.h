#ifndef FIND_LINK_VISITOR_H
#define FIND_LINK_VISITOR_H

#include "node_visitor.h"

class FindLinkVisitor : public NodeVisitor
{
public:
  FindLinkVisitor();

  void visitFile(File *file);
  void visitFolder(Folder *folder);
  void visitLink(Link *link);

  std::vector<Node *> getLinks()
  {
    return _links;
  }

private:
  std::vector<Node *> _links;
};

#endif
