#include "TermVar.h"
#include "Trail.h"

int TermVar::timestamp = 0;


bool TermVar::unify(Term *t) 
{
  if (instance!=this)
  {
    return instance->unify(t);
  }
  Trail::Push(this); 
  instance = t; 
  return true; 
}
Term *TermVar::copy() 
{
  if (instance==this)
  {
    Trail::Push(this); 
    instance = new TermVar();
  }
  return instance;
}

