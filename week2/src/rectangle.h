#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include<iostream>

using namespace::std;

#include "shape.h"
class Rectangle: public Shape
{
    public:
        Rectangle(double l, double w):_l(l), _w(w)
        {

        }

        double area() const
        {
            return _l * _w;
        }

        double perimeter() const
        {
            return 2 * (_l + _w);
        }
        /*
        double compactness() const
        {
            try
            {
                return SafeDivide(perimeter()*perimeter(), area());
            } 
            catch (const invalid_argument& e)
            {
                cout<<"Caught exception:"<<e.what()<<endl;
            }
        }
        */
        bool isRectangle()
        {
            if ((_l<=0)or(_w<=0))
            {
                return false;
            }
            else
            {
                return true;
            }
        }

    private:
        double _l;
        double _w;
        /*
        double SafeDivide(double num, double den) const
        {
            if(den==0)
            {
                throw invalid_argument("Division by zero.");
            }
            else
            {
                return num / den;
            }
        }
        */
};
#endif
