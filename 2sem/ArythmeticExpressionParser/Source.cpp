#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <functional>
#include "ifx2pfx.h"

int calcPostfixLong(std::string const& expr)
{
    std::stack<int> stack;
    char right, left;
    for (char curr : expr)
    {
        switch (curr)
        {
        case '+':
            right = stack.top(); stack.pop();
            left = stack.top(); stack.pop();
            stack.push(left + right);
            break;
        case '-':
            right = stack.top(); stack.pop();
            left = stack.top(); stack.pop();
            stack.push(left - right);
            break;
        case '*':
            right = stack.top(); stack.pop();
            left = stack.top(); stack.pop();
            stack.push(left * right);
            break;
        case '/':
            right = stack.top(); stack.pop();
            left = stack.top(); stack.pop();
            stack.push(left / right);
            break;
        default:
            stack.push(curr - '0');
        }
    }
    return stack.top();
}

// Refactor #1
std::map<char, std::function<int(int, int)>> operators =
{
    {'+', std::plus<int>() },
    {'-', std::minus<int>() },
    {'*', std::multiplies<int>() },
    {'/', std::divides<int>() }
};

int calcPostfixShort(std::string const& expr)
{
    std::stack<int> stack;
    for (char curr : expr)
    {
        if (isdigit(curr)) 
        {
            stack.push(curr-'0');
            continue;
        }
        char right = stack.top(); stack.pop();
        char left = stack.top(); stack.pop();
        stack.push(operators[curr](left,right));
    }
    return stack.top();
}

int main()
{
 /*   int(*calcPostfix)(std::string const&) = calcPostfixShort;
    std::string expr = "34*2+";
    std::cout << expr << " = " << calcPostfix(expr) << "\n";*/
    std::cout << infixToPostfix("2+3*4") << "\n";

    return 0;
}