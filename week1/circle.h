#include <math.h>

class Circle
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

    	bool test()
    	{
    		if (_r<=0){return false;}
    		else{return true;}
    	}

    private:
    	double _r;
};
