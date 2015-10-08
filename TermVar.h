#include <iostream>
#include <string.h>

#pragma once

#include "Term.h"
#include "TermCons.h"

class TermVar : public Term {
private:
    Term *instance;
    int varno;
    static int timestamp;
public:
    TermVar() : instance(this), varno(++timestamp) {}
    void print() 
    { 
      if (instance!=this) 
      {
        instance->print();
      }
      else 
      {
        std::cout<<"_"<<varno; 
      }
    };
    bool unify(Term *t);
    Term *copy();
    Term *reset() { instance = this; return this; }
private:
    bool unify2(TermCons *t) { return this->unify(t); }
};

