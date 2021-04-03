#include <iostream>
#include "String.h"

int main()
{
    String str = "hello world";
    String str2 = " of pain!";
    String str_full = str + str2;
    std::cout << str_full << "\n";

    std::cout << (String("abc") < String("def")) << "\n";

    String str_from_cin;
    std::cin >> str_from_cin;

    std::cout << str_from_cin;

    return 0;
}