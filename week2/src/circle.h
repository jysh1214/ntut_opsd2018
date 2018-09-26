#include <math.h>
#include <iostream>

using namespace::std;

class Circle: public Shape
{
    public:
        Circle(double r):_r(r)
        {

        }

        double area() const
        {
            return M_PI * _r *_r;
        }

        double perimeter() const
        {
            return 2 * M_PI * _r;
        }

        bool isCircle() const
        {
            if (_r<=0){return false;}
            else{return true;}
        }

    private:
        double _r;

};
