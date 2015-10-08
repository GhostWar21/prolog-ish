#include <iostream>
#include <string.h>

#pragma once

#include "TermVar.h"

class Trail {
private:
  TermVar *tcar;
  Trail *tcdr;
  static Trail *sofar;
  Trail(TermVar *h, Trail *t) : tcar(h), tcdr(t) {}
  ~Trail()
  {
    if(tcar != NULL) delete tcar;
    if(tcdr != NULL) delete tcdr;
  }
public:
    static Trail *Note() { return sofar; }
    static void Push(TermVar *x) { sofar = new Trail(x, sofar); }
    static void Undo(Trail *whereto)
    {   
      for (; sofar != whereto; sofar = sofar->tcdr)
            sofar->tcar->reset();
    }
};
