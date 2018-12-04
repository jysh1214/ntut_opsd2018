#ifndef NULL_ITERATOR
#define NULL_ITERATOR

#include "node_iterator.h"

class NullIterator : public NodeIterator
{
public:
  void first()
  {
    //definition by yourself
  }
  Node *currentItem()
  {
    return nullptr;
  }
  void next()
  {
    //definition by yourself
  }
  bool isDone()
  {
    return true;
  }
};

#endif
