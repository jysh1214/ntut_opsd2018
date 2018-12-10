#ifndef TRIANGLE_FACTORY_H
#define TRIANGLE_FACTORY_H

#include "triangle.h"

class TriangleFactory
{
public:
  TriangleFactory(){}
  virtual ~TriangleFactory(){}
  Triangle * create(int a, int b, int c);
};

#endif
