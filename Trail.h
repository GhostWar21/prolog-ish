#include <iostream>
#include <string.h>



class Trail {
private:
    TermVar *tcar;
    Trail *tcdr;
    static Trail *sofar;
    Trail(TermVar *h, Trail *t) : tcar(h), tcdr(t) {}
public:
    static Trail *Note() { return sofar; }
    static void Push(TermVar *x) { sofar = new Trail(x, sofar); }
    static void Undo(Trail *whereto)
    {   for (; sofar != whereto; sofar = sofar->tcdr)
            sofar->tcar->reset();
    }
};
Trail *Trail::sofar = NULL;

bool TermVar::unify(Term *t) { 
                               if (instance!=this) return instance->unify(t);
                               Trail::Push(this); instance = t; return true; }
Term *TermVar::copy() {
                        if (instance==this)
                        {   Trail::Push(this); instance = new TermVar();
                        }
                        return instance;
                      }

