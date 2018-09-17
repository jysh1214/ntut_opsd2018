#include <math.h>

class Triangle
{
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3)
        {

        }

        double area() const
        {
        	return heron();
        }

    	double perimeter() const
    	{
    		double _a = dis(_x1, _y1, _x2, _y2);
    	    double _b = dis(_x1, _y1, _x3, _y3);
    	    double _c = dis(_x2, _y2, _x3, _y3);

    		return _a + _b + _c;
    	}

    	bool isTriangle() const
    	{
    		double _a = dis(_x1, _y1, _x2, _y2);
    	    double _b = dis(_x1, _y1, _x3, _y3);
    	    double _c = dis(_x2, _y2, _x3, _y3);

    		if ((_a+_b>_c)and(_a+_c>_b)and(_b+_c>_a))
    		{
    			return true;
    		} 
            else
            {
            	return false;
            }
    	}

    private:
    	double _x1; double _y1;
    	double _x2; double _y2;
    	double _x3; double _y3;

    	double dis(double a, double b, double c, double d) const
    	{
    		double i = pow((a-c), 2);
    		double j = pow((b-d), 2);
            return sqrt(i+j);
    	}

    	double heron() const
    	{
    		double _a = dis(_x1, _y1, _x2, _y2);
    	    double _b = dis(_x1, _y1, _x3, _y3);
    	    double _c = dis(_x2, _y2, _x3, _y3);

    		double s = (_a + _b + _c)/2;
    		return sqrt(s*(s-_a)*(s-_b)*(s-_c));
    	}
};
