#include <iostream>
#include <string.h>

#pragma once


#include "Atom.h"
#include "Term.h"

class TermCons : public Term {
public:
    TermCons(Atom *f) : fsym(f), arity(0), args(NULL) { }

    TermCons(Atom *f, Term *a1) : fsym(f), arity(1), args(new Term*[1]) { args[0]=a1; };

    TermCons(Atom *f, Term *a1, Term *a2) : fsym(f), arity(2), args(new Term*[2]) { args[0]=a1, args[1]=a2; };

    TermCons(Atom *f, Term *a1, Term *a2, Term *a3) : fsym(f), arity(3), args(new Term*[3]) { args[0]=a1, args[1]=a2, args[2]=a3; };

    ~TermCons()
    {
	delete fsym;
        for(int i=0;i < arity; i++)
	  delete args[i];
        if(arity > 0)
          delete args;
    }
    void print() 
    {  
      fsym->print();
      if (arity>0)
      {   
         std::cout <<"( ";
         for (int i = 0; i<arity; )
         {
           args[i]->print();
           if (++i < arity) std::cout << ", ";
         }
         std::cout <<" )";
      }
    }
    bool unify(Term *t) 
    {
      return t->unify2(this);
    }
    Term *copy() 
    {
      return copy2();
    }
    TermCons *copy2() 
    { 
      return new TermCons(this); 
    }
private:
    TermCons(TermCons *p) : fsym(p->fsym), arity(p->arity), args(p->arity==0 ? NULL : new Term*[p->arity])
    { 
      for (int i=0; i<arity; i++) 
      {
        args[i] = p->args[i]->copy(); 
      }
    }
    bool unify2(TermCons *t) 
    { 
      if (!(fsym->eqatom(t->fsym) && arity == t->arity))
          return false;
      for (int i = 0; i<arity; i++)
          if (!args[i]->unify(t->args[i])) return false;
      return true;
    }
  int arity;
  Atom *fsym;
  Term **args;
};

