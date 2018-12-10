#ifndef SET_H
#define SET_H

#include <vector>
#include <string>
#include "obj.h"

using namespace std;

class Set: public Obj
{
public:
  Set();
  virtual ~Set(){}
  void add(Obj * o);
  string toString();
  bool isEmpty();
  int numberofElements();
  Set * getflatternedSet();
  vector <Obj*> getElements();
  void recursion(Set * answer, Obj * o);

private:
  vector <Obj *> _elements;
};

#endif
