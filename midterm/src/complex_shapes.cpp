#include "complex_shapes.h"

using namespace::std;

ComplexShapes::ComplexShapes(vector<Shape *> *shape): cs(shape)
{

}

double ComplexShapes::area() const
{
  double sum = 0;
  for (vector<Shape*>::iterator it = cs->begin() ; it != cs->end(); ++it)
  {
  	sum += (*it)->area();
  }
  return sum;
}

double ComplexShapes::perimeter() const
{
  double sum = 0;
  for (vector<Shape*>::iterator it = cs->begin() ; it != cs->end(); ++it)
  {
  	sum += (*it)->perimeter();
  }
  return sum;
}

void ComplexShapes::accept(FindAreaVisitor *fav)
{
  fav->visitComplexShapes(this);
}

void ComplexShapes::add(Shape *s)
{
  cs->push_back(s);
}

int ComplexShapes::numberOfChild()
{
    return cs->size();
}

Shape * ComplexShapes::getChild(int index)
{
    return (*cs)[index];
}
