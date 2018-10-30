#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include "shape.h"
#include "find_area_visitor.h"

class Ellipse: public Shape
{
public:
  Ellipse(double a, double b): _a(a), _b(b)
  {

  }

  double area() const
  {
    return M_PI * _a *_b;
  }

  double perimeter() const
  {
  	return 2 * M_PI * sqrt(((_a*_a)+(_b*_b))/2);
  }

  void accept(FindAreaVisitor *fav)
  {
    fav->visitEllipse(this);
  }

private:
  double _a;
  double _b;
};
#endif
