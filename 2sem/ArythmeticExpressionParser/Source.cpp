#include <iostream>
#include <string>
#include "ifx2pfx.h"
#include "calc_postfix.h"
#include "FormulaTree.h"

int main()
{
 /*   int(*calcPostfix)(std::string const&) = calcPostfixShort;
    std::string expr = "34*2+";
    std::cout << expr << " = " << calcPostfix(expr) << "\n";*/
    //std::cout << infixToPostfix("2+3*4") << "\n";
    Formula f("2+3*4");
    std::cout << f.str() << "=" << f.calc() << "\n";
    return 0;
}