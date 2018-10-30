#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "shape.h"
#include "find_area_visitor.h"

class Circle: public Shape
{
public:
  Circle(double r):_r(r)
  {

  }

  double area() const
  {
    return M_PI * _r * _r;
  }

  double perimeter() const
  {
    return 2 * M_PI * _r;
  }

  void accept(FindAreaVisitor *fav)
  {
    fav->visitCircle(this);
  }

  string classType() const
  {
    return "Circle";
  }

private:
  double _r;
};

#endif
