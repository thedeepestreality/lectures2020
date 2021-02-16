#include <iostream>
#include "mer_de_noms.h"

int main()
{
    //Variant 1
    mer_de_noms::test();

    //Variant2
    using mer_de_noms::test;
    test();

    //Variant 3
    using namespace mer_de_noms;
    test();
    second_f();

    mer_de_noms::apc::foo();

    std::cout << platypus() << '\n';
 
    return 0;
}