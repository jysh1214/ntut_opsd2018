#include <gtest/gtest.h>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST (ShapeTest, first)
{
    ASSERT_TRUE(true);
}

TEST (ShapeTest, Circle)
{
    Circle c(10.0);
    ASSERT_TRUE(c.test());
    ASSERT_NEAR(314.159, c.area(), 0.001);
    ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST (ShapeTest, Triangle)
{
    Triangle t(3.0, 4.0, 5.0);
    ASSERT_TRUE(t.test());
    ASSERT_NEAR(6.0, t.area(), 0.001);
    ASSERT_NEAR(12.0, t.perimeter(), 0.001);
}

TEST (ShapeTest, Rectangle)
{
    Rectangle r(5.0, 10.0);
    ASSERT_TRUE(r.test());
    ASSERT_NEAR(50.0, r.area(), 0.001);
    ASSERT_NEAR(30.0, r.perimeter(), 0.001);
}

TEST (ShapeTest, Circle)
{
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
    ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST (ShapeTest, Triangle)
{
    Triangle t(3.0, 4.0);
    ASSERT_NEAR(6.0, t.area(), 0.001);
    ASSERT_NEAR(12.0, t.perimeter(), 0.001);
}

TEST (ShapeTest, Rectangle)
{
    Rectangle r(5.0, 10.0);
    ASSERT_NEAR(50.0, r.area(), 0.001);
    ASSERT_NEAR(30.0, r.perimeter(), 0.001);
}
