#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H

#include <vector>
#include "shape.h"
#include "find_area_visitor.h"

using namespace::std;

class ComplexShapes: public Shape
{
public:
  ComplexShapes(vector<Shape *> *shape);
  double area() const ;
  double perimeter() const;
  void accept(FindAreaVisitor *fav);

  void add(Shape *s);
  int numberOfChild();
  Shape * getChild(int index);

private:
  vector<Shape *> *cs;
};
#endif
