#ifndef NODE_H
#define NODE_H

#include <sys/stat.h>
#include <string>
#include <map>

#include "node_iterator.h"
#include "null_iterator.h"

class NodeVisitor;
class InfoContentVisitor;
class FindVisitor;
class FindLinkVisitor;

class Node
{
public:
  Node(const char *path) : _path(path)
  {
    lstat(_path, &_st);
    if (lstat(_path, &_st) == -1)
    {
      throw std::string("No such file or directory.");
    }
  }

  int size() const
  {
    return _st.st_size;
  }

  virtual void add(Node *node)
  {
    throw std::string("unable to add\n");
  }

  virtual int numberOfChildren() const
  {
    throw std::string("number of children: not applicable\n");
  }

  std::string getPath() const
  {
    return _path;
  }

  virtual void accept(NodeVisitor *nodeVisitor) = 0;

  virtual std::map<std::string, Node *> getChildren() {}

  std::string name() const
  {
    std::string nodeName;
    std::string tempStr = this->_path;
    nodeName = tempStr.substr(tempStr.find_last_of("/") + 1, tempStr.length() - tempStr.find_last_of("/"));

    return nodeName;
  }

  virtual NodeIterator *createIterator()
  {
    return new NullIterator();
  }

private:
  const char *_path;
  struct stat _st;
};

#endif
