#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"

TEST (ShapeTest, first)
{
    ASSERT_TRUE(true);
}

TEST (ShapeTest, Circle)
{
    Circle c(10.0);
    ASSERT_TRUE(c.isCircle());
    ASSERT_NEAR(314.159, c.area(), 0.001);
    ASSERT_NEAR(62.831, c.perimeter(), 0.001);
    ASSERT_NEAR(12.566, c.compactness(), 0.001);
}

TEST (ShapeTest, Triangle)
{
    Triangle t(-3.0, 0.0, 0.0, 0.0, 0.0, 4.0);
    ASSERT_TRUE(t.isTriangle());
    ASSERT_NEAR(6.0, t.area(), 0.001);
    ASSERT_NEAR(12.0, t.perimeter(), 0.001);
    ASSERT_NEAR(24.0, t.compactness(), 0.001);
}

TEST (ShapeTest, Rectangle)
{
    Rectangle r(5.0, 10.0);
    ASSERT_TRUE(r.isRectangle());
    ASSERT_NEAR(50.0, r.area(), 0.001);
    ASSERT_NEAR(30.0, r.perimeter(), 0.001);
    ASSERT_NEAR(18.0, r.compactness(), 0.001);
}
