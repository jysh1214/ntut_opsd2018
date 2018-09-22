#include <gtest/gtest.h>
#include <vector>
#include "../src/sort.h"

using namespace::std;

TEST(SortTest, first)
{
    ASSERT_TRUE(true);
}

TEST(SortTest, sortAreaAscending)
{
    Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor(test_array, test_array+4);
    Sort *s = new Sort(&myvetor);
    //s->sortArea([](Shape *a, Shape *b){return a->area() < b->area();});

    //sort(test_array, test_array+4, [](Shape *a, Shape *b){return a->area() < b->area();});
    //ASSERT_NEAR(0.75, test_array[0]->area(), 0.001);
    //ASSERT_NEAR(0.25*3.1415, test_array[1]->area(), 0.001);
    //ASSERT_NEAR(3.1415, test_array[2]->area(), 0.001);
    //ASSERT_NEAR(30, test_array[3]->area(), 0.001);
}
/*
TEST(SortTest, sortAreaDescending)
{
    Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor(test_array, test_array+4);
    Sort <Shape*>s(myvetor);
    s.sortArea([](Shape *a, Shape *b){return a->area() > b->area();});

    //sort(test_array, test_array+4, [](Shape *a, Shape *b){return a->area() < b->area();});
    ASSERT_NEAR(0.75, test_array[3]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array[2]->area(), 0.001);
    ASSERT_NEAR(3.1415, test_array[1]->area(), 0.001);
    ASSERT_NEAR(30, test_array[0]->area(), 0.001);
}*/
/*
TEST (SortTest, Sorting)
{
    //You should implement area ascending and descending lamda function as parameter for Sort::sortArea()
    Shape* test_array_1[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
 
    sort(test_array_1, test_array_1+4, [](Shape *a, Shape *b){return a->area() < b->area();});
    ASSERT_NEAR(0.75, test_array_1[0]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_1[1]->area(), 0.001);
    ASSERT_NEAR(3.1415, test_array_1[2]->area(), 0.001);
    ASSERT_NEAR(30, test_array_1[3]->area(), 0.001);

    Shape* test_array_2[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
 
    sort(test_array_2, test_array_2+4, [](Shape *a, Shape *b){return a->area() > b->area();});
    ASSERT_NEAR(0.75, test_array_2[3]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_2[2]->area(), 0.001);
    ASSERT_NEAR(3.1415, test_array_2[1]->area(), 0.001);
    ASSERT_NEAR(30, test_array_2[0]->area(), 0.001);


    //You should use those functions as parameter for Sort::sortPerimeter()
    Shape* test_array_3[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};

    sort(test_array_3, test_array_3+4, perimeterAscendingComparison(Shape *a, Shape *b));
    ASSERT_NEAR(0.75, test_array_3[0]->perimeter(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_3[1]->perimeter(), 0.001);
    ASSERT_NEAR(3.1415, test_array_3[2]->perimeter(), 0.001);
    ASSERT_NEAR(30, test_array_3[3]->perimeter(), 0.001);

    Shape* test_array_4[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};

    sort(test_array_4, test_array_4+4, perimeterDescendingComparison(Shape *a, Shape *b)); 
    ASSERT_NEAR(0.75, test_array_4[3]->perimeter(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_4[2]->perimeter(), 0.001);
    ASSERT_NEAR(3.1415, test_array_4[1]->perimeter(), 0.001);
    ASSERT_NEAR(30, test_array_4[0]->perimeter(), 0.001);

    //You should use those objects as parameter for Sort::sortCompactness()
    Shape* test_array_5[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};

    sort(test_array_5, test_array_5+4, CompactnessAscendingComparison(Shape *a->compactness(), Shape *b->compactness()).op);
    ASSERT_NEAR(0.75, test_array_5[0]->compactness(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_5[1]->compactness(), 0.001);
    ASSERT_NEAR(3.1415, test_array_5[2]->compactness(), 0.001);
    ASSERT_NEAR(30, test_array_5[3]->compactness(), 0.001);

    Shape* test_array_6[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    
    sort(test_array_6, test_array_6+4, CompactnessDescendingComparison(Shape *a->compactness(), Shape *b->compactness()).op);
    ASSERT_NEAR(0.75, test_array_6[3]->compactness(), 0.001);
    ASSERT_NEAR(0.25*3.1415, test_array_6[2]->compactness(), 0.001);
    ASSERT_NEAR(3.1415, test_array_6[1]->compactness(), 0.001);
    ASSERT_NEAR(30, test_array_6[0]->compactness(), 0.001);

}

bool perimeterDescendingComparison(Shape *a, Shape *b)
{
    return a->area() > b->area();
}

bool perimeterAscendingComparison(Shape *a, Shape *b);
{
    return a->area() < b->area();
}

//You should use those objects as parameter for Sort::sortCompactness()
class CompactnessAscendingComparison
{
    public:
        CompactnessAscendingComparison(Shape *a, Shape *b):Shape *_a(*a), Shape *_b(*b)
        {
            op = _a->compactness() < _b->compactness();
        }

    private:
        Shape *_a;
        Shape *_b;
        bool op;
};

class CompactnessDescendingComparison
{
    public:
        CompactnessDescendingComparison(Shape *a, Shape *b):Shape *_a(*a), Shape *_b(*b)
        {
            op = _a->compactness() > _b->compactness();
        }

    private:
        Shape *_a;
        Shape *_b;
        bool op;
};
*/
