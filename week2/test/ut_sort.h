#include <gtest/gtest.h>
#include <vector>
#include "../src/sort.h"

using namespace::std;

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
        bool operator() (Shape *a, Shape *b) const
        { 
            return a->compactness() < b->compactness();
        }
}cac;

class CompactnessDescendingComparison
{
    public:
        bool operator() (Shape *a, Shape *b) const
        {
            return a->compactness() > b->compactness();
        }
}cdc;


TEST(SortTest, first)
{
    ASSERT_TRUE(true);
}

TEST(SortTest, sortAreaAscending)
{
    Shape* test_array_1[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_1(test_array_1, test_array_1+4);
    Sort *s_1 = new Sort(&myvetor_1);
    s_1->sortArea([](Shape *a, Shape *b){return a->area() < b->area();});
    ASSERT_NEAR(0.75, myvetor_1[0]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, myvetor_1[1]->area(), 0.001);
    ASSERT_NEAR(3.1415, myvetor_1[2]->area(), 0.001);
    ASSERT_NEAR(30, myvetor_1[3]->area(), 0.001);
}

TEST(SortTest, sortAreaDescending)
{
    Shape* test_array_2[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_2(test_array_2, test_array_2+4);
    Sort *s_2 = new Sort(&myvetor_2);
    s_2->sortArea([](Shape *a, Shape *b){return a->area() > b->area();});
    ASSERT_NEAR(0.75, myvetor_2[3]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, myvetor_2[2]->area(), 0.001);
    ASSERT_NEAR(3.1415, myvetor_2[1]->area(), 0.001);
    ASSERT_NEAR(30, myvetor_2[0]->area(), 0.001);
}

TEST(SortTest, sortPerimeterAscending)
{
    Shape* test_array_3[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_3(test_array_3, test_array_3+4);
    Sort *s_3 = new Sort(&myvetor_3);
    s_3->sortPerimeter(perimeterAscendingComparison);
    ASSERT_NEAR(3.1415, myvetor_3[0]->perimeter(), 0.001);
    ASSERT_NEAR(4.0, myvetor_3[1]->perimeter(), 0.001);
    ASSERT_NEAR(6.2830, myvetor_3[2]->perimeter(), 0.001);
    ASSERT_NEAR(22.0, myvetor_3[3]->perimeter(), 0.001);
}

TEST(SortTest, sortPerimeterDescending)
{
    Shape* test_array_4[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_4(test_array_4, test_array_4+4);
    Sort *s_4 = new Sort(&myvetor_4);
    s_4->sortPerimeter(perimeterDescendingComparison);
    ASSERT_NEAR(3.1415, myvetor_4[3]->perimeter(), 0.001);
    ASSERT_NEAR(4.0, myvetor_4[2]->perimeter(), 0.001);
    ASSERT_NEAR(6.2830, myvetor_4[1]->perimeter(), 0.001);
    ASSERT_NEAR(22.0, myvetor_4[0]->perimeter(), 0.001);
}

TEST(SortTest, sortCompactnessAscending)
{
    Shape* test_array_5[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_5(test_array_5, test_array_5+4);
    Sort *s_5 = new Sort(&myvetor_5);
    s_5->sortCompactness(cac);
    ASSERT_NEAR(12.5664, myvetor_5[0]->compactness(), 0.001);
    ASSERT_NEAR(12.5664, myvetor_5[1]->compactness(), 0.001);
    ASSERT_NEAR(16.1333, myvetor_5[2]->compactness(), 0.001);
    ASSERT_NEAR(21.3333, myvetor_5[3]->compactness(), 0.001);
}

TEST(SortTest, sortCompactnessDescending)
{
    Shape* test_array_6[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5.0, 6.0), new Rectangle(0.5, 1.5)};
    vector<Shape*> myvetor_6(test_array_6, test_array_6+4);
    Sort *s_6 = new Sort(&myvetor_6);
    s_6->sortCompactness(cdc);
    ASSERT_NEAR(12.5664, myvetor_6[3]->compactness(), 0.001);
    ASSERT_NEAR(12.5664, myvetor_6[2]->compactness(), 0.001);
    ASSERT_NEAR(16.1333, myvetor_6[1]->compactness(), 0.001);
    ASSERT_NEAR(21.3333, myvetor_6[0]->compactness(), 0.001);
}
