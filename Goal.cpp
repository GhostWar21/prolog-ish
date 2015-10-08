#include "Goal.h"
#include "TermVarMapping.h"
#include "Clause.h"
#include "Trail.h"
#include "Program.h"

#define indent( n) { for (int i = 0; i<n; i++) std::cout << "    "; }

void Goal::solve(Program *p, int level, TermVarMapping *map)
{   
   indent(level); 
   std::cout << "solve@"  << level << ": ";
   this->print(); 
   std::cout << "\n";

   for (Program *q = p; q != NULL; q = q->pcdr)
   {
     Trail *t = Trail::Note();
     Clause *c = q->pcar->copy();
     Trail::Undo(t);
     indent(level); std::cout << "  try:"; c->print(); std::cout << "\n";
     if (car->unify(c->head))
     {
       Goal *gdash = c->body==NULL ? cdr : c->body->append(cdr);
       if (gdash == NULL) map->showanswer();
       else gdash->solve(p, level+1, map);
     }
     else
     {
       indent(level); std::cout << "  nomatch.\n";
     }
     Trail::Undo(t);
    }
}

