#include <iostream>
#include <string.h>


class Program {
public:
    Clause *pcar;
    Program *pcdr;
    Program(Clause *h, Program *t) : pcar(h), pcdr(t) {}
};

