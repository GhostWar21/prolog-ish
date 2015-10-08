#include <iostream>
#include <string.h>

#pragma once

class Atom 
{
public: 
  Atom(std::string s) : name(s) {}
  ~Atom() {}
  void print() { std::cout<<name; }
  bool eqatom(Atom *t) { return this->name == t->name; }
private:
  std::string name;
};

