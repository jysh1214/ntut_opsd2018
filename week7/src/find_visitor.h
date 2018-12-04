#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H

#include "node_visitor.h"

class FindVisitor : public NodeVisitor
{
public:
  FindVisitor(std::string name);

  void visitFile(File *file);
  void visitFolder(Folder *folder);
  void visitLink(Link *link);

  void FindSameNodeName(Node *n, std::vector<Node *> &answer);

  std::string findResult()
  {
    return _nodeNamePath;
  }

private:
  std::string _name;
  std::string _nodeNamePath;
};

#endif
