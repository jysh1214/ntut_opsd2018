#ifndef INT_H
#define INT_H

#include <string>
#include "obj.h"

using namespace std;

class Int: public Obj
{
public:
  Int(int i);
  virtual ~Int(){}
  string toString();
  int getInt();

private:
  int _i;
};
#endif
