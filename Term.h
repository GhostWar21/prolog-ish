#include <iostream>
#include <string.h>


class TermCons;

class Term {
  public: virtual void print() = 0;
  public: virtual bool unify(Term *) = 0;
  public: virtual bool unify2(TermCons *) = 0;
  public: virtual Term *copy() = 0;
};

