#include <iostream>
#include <string.h>

void indent(int n) {   for (int i = 0; i<n; i++) std::cout << "    "; }

class Atom {
    std::string atomname;
public: Atom(std::string s) : atomname(s) {}
    void print() { std::cout<<atomname; }
    bool eqatom(Atom *t) { return this->atomname == t->atomname; }
};

