#include "int.h"

using namespace std;

Int::Int(int i): _i(i){}

string Int::toString()
{
  return to_string(_i);
}

int Int::getInt()
{
  return _i;
}
