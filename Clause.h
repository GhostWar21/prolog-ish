#include <iostream>
#include <string.h>

#pragma once
#include "TermCons.h"
#include "Goal.h"

class Clause 
{
public:
  TermCons *head;
  Goal *body;
  Clause(TermCons *h, Goal *t) : head(h), body(t) {}
  Clause *copy() 
  { 
    return new Clause(head->copy2(), body==NULL ? NULL : body->copy()); 
  }
  void print() 
  { 
    head->print();
    std::cout << " :- ";
    if (body==NULL)
    {
      std::cout << "true";
    }
    else 
    {
      body->print();
    }
  }
};

