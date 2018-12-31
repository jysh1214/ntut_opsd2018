#ifndef _SORT_H
#define _SORT_H

#include <algorithm>
#include <vector>

using namespace::std;
template<class T> void sortArea(T);
template<class T> void sortPerimeter(T);
template<class T> void sortCompactness(T);

bool perimeterAscendingComparison(Shape *a, Shape *b)
{
    return a->perimeter() < b->perimeter();
}

bool perimeterDescendingComparison(Shape *a, Shape *b)
{
    return a->perimeter() > b->perimeter();
}

class CompactnessAscendingComparison
{
    public:
        bool operator() (Shape *a, Shape *b)
        { 
            return (a->compactness() < b->compactness());
        }
};

class CompactnessDescendingComparison
{
    public:
        bool operator() (Shape *a, Shape *b)
        {
            return (a->compactness() > b->compactness());
        }
};

class Sort
{
    public:
        Sort(vector<Shape*> *v):_v(v)
        {

        }

        //The argument ** Accept comparsion ** can accept lambda, function, and object
        //You should implement area ascending and descending lamda function as parameter for Sort::sortArea()
        template<class T> 
        void sortArea(T comparsion)
        {
            sort(_v->begin(), _v->end(), comparsion);
        }
        
        //You should use those functions as parameter for Sort::sortPerimeter()
        template<class T> 
        void sortPerimeter(T comparsion)
        {
            sort(_v->begin(), _v->end(), comparsion);
        }

        //You should use those objects as parameter for Sort::sortCompactness()
        template<class T> 
        void sortCompactness(T comparsion)
        {
            sort(_v->begin(), _v->end(), comparsion);
        }

    private:
        vector<Shape*>*_v;
};
#endif
