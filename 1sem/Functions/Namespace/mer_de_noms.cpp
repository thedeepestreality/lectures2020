#include "mer_de_noms.h"
#include <iostream>

namespace mer_de_noms
{
    int glob = 42;

    void hidden()
    {
        std::cout << "I'm a secret\n";
    }

    void test()
    {
        std::cout << "Judith\n";
    }

    void second_f()
    {
        std::cout << "Orestes\n";
    }
}