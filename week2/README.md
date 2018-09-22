# Pattern Oriented Software Design
#### Fall, 2018
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

#### Homework 2

# Purpose of the homework:
  Using different ways to pass compare function
  1. lambda function
  2. function
  3. object

  See [C++ Reference std::sort](http://www.cplusplus.com/reference/algorithm/sort/ "std::Sort")
# Requirements:
 1. Create `shape.h`. with following interface below.

        class Shape {
        ...
            virtual double area() const = 0;
            virtual double perimeter() const = 0;
        ...
        }
 2. `Circle`, `Triangle`, `Rectangle` should inherit `Shape`.

 3. Implement `compactness()` method for each class.

        Compactness Formula : P^2 / A

        P = Perimeter ; A = Area
        Note:If Area = 0.Throw an exception string "Division by zero".

       reference:https://books.google.com.tw/books?id=zMFQDwAAQBAJ&pg=PA438&lpg=PA438&dq=If+Area+%3D+0.Throw+an+exception+string+%22Division+by+zero%22.&source=bl&ots=K9f1FFwUYC&sig=h4xiQq8c0HWeQR1dadgCnymeBb4&hl=en&sa=X&ved=2ahUKEwjcrL352s3dAhXIXrwKHUitBSwQ6AEwA3oECAgQAQ#v=onepage&q=If%20Area%20%3D%200.Throw%20an%20exception%20string%20%22Division%20by%20zero%22.&f=false

 4. Create `sort.h`. with following interface below:

    **Note: Each class constructor below are the skeleton. You should finish implementation by yourself.**

```
class Sort{
    public:
      Sort(std::vector* v): _v(v){}

      // The argument ** Accept comparison ** can accept lambda, function, and object
      void sortArea(** Accept comparison **)

      void sortPerimeter(** Accept comparison **)

      void sortCompactness(** Accept comparison **)

    private:
      std::vector* _v;
};

//You should implement area ascending and descending lamda function as parameter for Sort::sortArea()

//You should use those functions as parameter for Sort::sortPerimeter()
bool perimeterDescendingComparison(Shape *a, Shape *b);

bool perimeterAscendingComparison(Shape *a, Shape *b);

//You should use those objects as parameter for Sort::sortCompactness()
class CompactnessAscendingComparison{
};

class CompactnessDescendingComparison{
};
```

5. Modify `Triangle` constuctor, If the vertex can not construct a triangle. Throw an exception string  "Not a triangle".

6. Create `ut_main.cpp`, `ut_sort.cpp`.

The `ut_main.cpp` should include `ut_sort.cpp` and  `ut_shape.cpp`.

refernece:https://stackoverflow.com/questions/19547091/including-cpp-files

Write the sortunit  test in `ut_sort.cpp`.

Modify ut_shape.cpp `TEST(triangle, isTriangle)` assertion.

Change assertion to assert exception string which is equal to "Not a triangle".

7. Write the corresponding makefile to generate executable file which named **`hw2`**.

8. Make sure your project structure should be the same as [course project directory](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2018f "yccheng/posd2018f")


# Note
Make sure your tests on local are all pass. Then you can push to Gitlab and watch the report on Jenkins.
