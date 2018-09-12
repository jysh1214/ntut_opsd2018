#include <math.h>

class Triangle
{
    public:
        Triangle(double a_side, double b_side, double c_side):_a(a_side), _b(b_side), _c(c_side)
        {

        }

        double area() const
        {
        	return heron();
        }

    	double perimeter() const
    	{
    		return _a + _b + _c;
    	}

    	bool test()
    	{
    		if ((_a+_b>=_c)and(_a+_c>=_b)and(_b+_c>=_a))
    		{
    			return true;
    		} 
            else
            {
            	return false;
            }
    	}

    private:
    	double _a;
    	double _b;
    	double _c;

    	double heron() const
    	{
    		double s = (_a + _b + _c)/2;
    		return sqrt(s*(s-_a)*(s-_b)*(s-_c));
    	}
};
