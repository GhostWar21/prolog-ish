#include <iostream>
#include <string.h>

#pragma once

class TermCons;

class Term 
{
public: 
  virtual void print() = 0;
  virtual bool unify(Term *) = 0;
  virtual bool unify2(TermCons *) = 0;
  virtual Term *copy() = 0;
};

