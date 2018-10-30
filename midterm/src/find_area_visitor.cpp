#include "complex_shapes.h"
#include "find_area_visitor.h"

/* error: invalid use of incomplete type ‘class ComplexShapes’
have to #include "complex_shapes.h"
*/

FindAreaVisitor::FindAreaVisitor(double min, double max): _min(min), _max(max)
{
  _totalFind;
}

void FindAreaVisitor::visitCircle(Circle *circle)
{
  _totalFind.clear(); //reset
}

void FindAreaVisitor::visitComplexShapes(ComplexShapes *complexshapes)
{
  _totalFind.clear(); //reset
  vector<Shape *> temp;
  this->recursion(complexshapes, temp); //recursion

  for (vector<Shape*>::iterator it = temp.begin() ; it != temp.end(); ++it)
  {
  	_totalFind.push_back((*it));
  }
}

void FindAreaVisitor::recursion(Shape * shape, vector<Shape *>& answer)
{
  try
  {
    if(shape->numberOfChild());
    for (int i = 0; i < shape->numberOfChild(); i++)
    {
      double x = (shape->getChild(i))->area();
      if ((_min<=x)&&(x<=_max))
      {
        answer.push_back(shape->getChild(i));
      }
      this->recursion(shape->getChild(i), answer);
    }    
  }
  catch (std::string e)
  {
    e = "error";
  }
}

void FindAreaVisitor::visitEllipse(Ellipse *ellipse)
{
  _totalFind.clear(); //reset
}

void FindAreaVisitor::visitRectangle(Rectangle *rectangle)
{
  _totalFind.clear(); //reset
}
