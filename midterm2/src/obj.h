#ifndef OBJ_H
#define OBJ_H

#include <vector>
#include <string>

using namespace std;

class Set;

class Obj
{
public:
  Obj(){}
  virtual ~Obj(){}
  virtual void add(Obj * o) {throw string("error");}
  virtual string toString() {throw string("error");}
  virtual int numberofElements() {throw string("error");}
  virtual int getInt() {throw string("error");}
  virtual vector<Obj*> getElements() {throw string("error");}
  virtual Set * getflatternedSet() {throw string("error");}
};

#endif
