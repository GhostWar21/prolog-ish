#include <iostream>
#include <string.h>







class TermVarMapping {
private:
    TermVar **varvar;
    std::string *vartext;
    int size;
public:
    TermVarMapping(TermVar *vv[], std::string vt[], int vs)
        :varvar(vv), vartext(vt), size(vs) {}
    void showanswer()
    {   if (size == 0) std::cout << "yes\n";
        else
        {   for (int i = 0; i < size; i++)
            {   std::cout << vartext[i] << " = "; varvar[i]->print(); std::cout << "\n";
            }
        }
    }
};

