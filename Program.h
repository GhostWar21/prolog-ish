#include <iostream>
#include <string.h>

#pragma once
#include "Clause.h"

class Program {
public:
    Clause *pcar;
    Program *pcdr;
    Program(Clause *h, Program *t) : pcar(h), pcdr(t) {}
};

