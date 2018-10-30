#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "find_area_visitor.h"

class Shape
{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;

  virtual void accept(FindAreaVisitor *fav)
  {

  }
  
  virtual int numberOfChild();
  virtual Shape * getChild(int index);
};
#endif
