#ifndef UT_TEST_H
#define UT_TEST_H

#include "../src/triangle.h"
#include "../src/triangle_factory.h"
#include "../src/obj.h"
#include "../src/set.h"
#include "../src/int.h"

// problem 1
TEST (TEST, TrianglewithNormalSides)
{
    ASSERT_NO_THROW(Triangle t(1, 2, 2));
}

TEST (TEST, TrianglewithIllegalSides)
{
    ASSERT_ANY_THROW(Triangle t(1, 2, 4));
}

// problem 2
TEST (TEST, TriangleFactorywithNormalSides)
{
    TriangleFactory * tf;
    ASSERT_NO_THROW(tf->create(1, 2, 2));
}

TEST (TEST, TriangleFactorywithIllegalSides)
{
    TriangleFactory * tf;
    ASSERT_NO_THROW(tf->create(1, 2, 4));
    ASSERT_EQ(nullptr, tf->create(1, 2, 4));
}

class SetTEST: public ::testing::Test
{
protected:
  void SetUp() override
  {
    set1 = new Set(); // {}

    set2 = new Set(); // {5, set1}
       five = new Int(5);
       set2->add(five);
       set2->add(set1);

    set3 = new Set(); // {3, 4, set2}
       three = new Int(3);
       four = new Int(4);
       set3->add(three);
       set3->add(four);
       set3->add(set2);

    set4 = new Set(); // {2}
       two = new Int(2);
       set4->add(two);

    set5 = new Set(); // {1, set4, set3}
       one = new Int(1);
       set5->add(one);
       set5->add(set4);
       set5->add(set3);
  }

  void TearDown() override
  {
    delete set1;
    delete set2;
    delete set3;
    delete set4;
    delete set5;

    delete five;
    delete four;
    delete three;
    delete two;
    delete one;
  }

  Obj * set1;
  Obj * set2;
  Obj * set3;
  Obj * set4;
  Obj * set5;

  Obj * five;
  Obj * four;
  Obj * three;
  Obj * two;
  Obj * one;
};

// problem 3
TEST_F (SetTEST, SetAddTEST) 
{
    ASSERT_EQ(3, set5->numberofElements());
}

// problem 4
TEST_F (SetTEST, SetAddTEST2) 
{
    ASSERT_EQ("{1,{2},{3,4,{5,{}}}}", set5->toString());
}

// problem 5
TEST_F (SetTEST, FlattenedSetTEST) 
{
    Set * orderSet = new Set();
    orderSet->add(one);
    orderSet->add(two);
    orderSet->add(three);
    orderSet->add(four);
    orderSet->add(five);

    ASSERT_EQ("{1,2,3,4,5}", orderSet->toString());

    Set * flatternedSet = set5->getflatternedSet();
    ASSERT_EQ("{1,2,3,4,5}", flatternedSet->toString());
    ASSERT_EQ(orderSet->toString(), flatternedSet->toString());
}
#endif
