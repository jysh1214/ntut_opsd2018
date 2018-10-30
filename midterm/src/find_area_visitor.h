#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H

#include <vector>
/*
cannot # include Shape & Circle
call circularly:
  include "shape.h" in find_area_visitor.h
  include "find_area_visitor.h" in shape.h
*/
class Shape;
class Circle;
class Ellipse;
class Rectangle;
class ComplexShapes;

using namespace::std;

class FindAreaVisitor 
{
public:
  FindAreaVisitor(double min, double max);
  void visitCircle(Circle *circle);
  void visitEllipse(Ellipse *ellipse);
  void visitRectangle(Rectangle *rectangle);
  void visitComplexShapes(ComplexShapes *complexshapes);
  void recursion(Shape * shape, vector<Shape *>& answer);
  vector<Shape *> findResult()
  {
  	return _totalFind;
  }

private:
  double _min;
  double _max;
  vector<Shape *> _totalFind;
};
#endif
