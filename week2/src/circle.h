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


        double compactness() const
        {
            try
            {
                return SafeDivide(pow(perimeter(), 2), area());
            } 
            catch (const invalid_argument& e)
            {
                cout<<"Caught exception:"<<e.what()<<endl;
            }
        }

        bool isCircle() const
        {
            if (_r<=0){return false;}
            else{return true;}
        }

    private:
        double _r;

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
};
