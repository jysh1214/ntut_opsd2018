#include <string>
#include "triangle_factory.h"

using namespace std;

Triangle * TriangleFactory::create(int a, int b, int c)
{
  try
  {
    return new Triangle(a, b, c);
  }
  catch (string e)
  {
    return nullptr;
  }
}
