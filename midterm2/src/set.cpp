#include "set.h"

using namespace std;

Set::Set()
{
  _elements.clear();
}
void Set::add(Obj * o)
{
  _elements.push_back(o);
}
string Set::toString()
{
  string temp;
  temp = "{";

  for (vector<Obj*>::iterator it = _elements.begin(); it != _elements.end(); it ++)
  {
    temp += (*it)->toString();
    if (it != _elements.end() - 1) temp += ",";
  }
  temp += "}";
  return temp;
}
bool Set::isEmpty()
{
  if (_elements.size() > 0) return false;
  else return true;
}
int Set::numberofElements()
{
  return _elements.size();
}
Set * Set::getflatternedSet()
{
  Set * newSet = new Set();
  recursion(newSet, this);
  return newSet;
}
void Set::recursion(Set * answer, Obj * o)
{
  try
  {
    o->getInt();
    answer->add(o);
  }
  catch (string e)
  {
    vector<Obj*> elements = o->getElements();
    for (vector<Obj*>::iterator it = elements.begin(); it != elements.end(); it ++)
    {
      this->recursion(answer, (*it));
    }
  }
}

vector <Obj*> Set::getElements()
{
  return _elements;
}
