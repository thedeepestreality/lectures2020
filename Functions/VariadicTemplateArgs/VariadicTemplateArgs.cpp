#include <iostream>
#include "composition.h"

int main()
{
    std::cout << compose<sqr, 3>(2) << '\n';
    return 0;
}