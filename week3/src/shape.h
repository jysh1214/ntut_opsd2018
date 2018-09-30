#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual double compactness()
        {
            if (this->area()==0)
            {
                throw std::string("Division by zero");
            }
            else
            {
                return (this->perimeter()*this->perimeter())/this->area();
            }
        }
};
#endif
