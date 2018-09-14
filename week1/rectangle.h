class Rectangle
{
    public:
        Rectangle(double length, double width):_l(length), _w(width)
        {

        }

        double area() const
        {
            return _l * _w;
        }

    	double perimeter() const
    	{
    		return 2 * _l + 2 * _w;
    	}

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
};
