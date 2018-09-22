#include <algorithm>
#include <vector>

using namespace::std;
//template<class T> 

class Sort
{
	public:
		Sort(vector<Shape*> *v):_v(v)
		{

		}

		//The argument ** Accept comparsion ** can accept lambda, function, and object
		//You should implement area ascending and descending lamda function as parameter for Sort::sortArea()
		/*
		void sortArea(T comparsion)
		{
            sort(_v->begin(), _v->end(), comparsion);
		}
        //You should use those functions as parameter for Sort::sortPerimeter()
		void sortPerimeter(T comparsion)
		{
            sort(_v->begin(), _v->end(), comparsion);
		}
        //You should use those objects as parameter for Sort::sortCompactness()
		void sortCompactness(T comparsion)
		{
            sort(_v->begin(), _v->end(), comparsion);
		}
		*/

	private:
		vector<Shape*>*_v;
};

