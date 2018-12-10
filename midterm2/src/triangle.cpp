#include <string>
#include "triangle.h"

using namespace std;

bool illegalTriangle(int a, int b, int c)
{
  if ((a+b>c)&&(a+c>b)&&(b+c>a)) return false;
  else return true;
}

Triangle::Triangle(int a, int b, int c): _a(a), _b(b), _c(c)
{
  if (illegalTriangle(_a, _b, _c)) throw string("illegal triangle");
}
