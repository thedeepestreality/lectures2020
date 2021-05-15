#pragma once
#include <map>
#include <stack>
#include <string>
#include <sstream>

enum Action {   ch2ex, 
                ch2st, 
                st2ex, 
                fin};

Action const ActionTable[5][6] =
{
    //   0     +      -      *      /      N
    {   fin, ch2st, ch2st, ch2st, ch2st, ch2ex }, // 0
    { st2ex, st2ex, st2ex, ch2st, ch2st, ch2ex }, // +
    { st2ex, st2ex, st2ex, ch2st, ch2st, ch2ex }, // -
    { st2ex, st2ex, st2ex, st2ex, st2ex, ch2ex }, // *
    { st2ex, st2ex, st2ex, st2ex, st2ex, ch2ex }  // /
};

std::map<char, size_t> Char2Index =
{
    { '\0',0 },
    { '+', 1 },
    { '-', 2 },
    { '*', 3 },
    { '/', 4 }
};

size_t ActionColumn(char curr)
{
    return isdigit(curr) ? 5 : Char2Index[curr];
}

size_t ActionRow(std::stack<char>& stack)
{
    if (stack.empty())
        return 0;
    return Char2Index[stack.top()];
}

std::string infixToPostfix(std::string const& input)
{
    std::stringstream str_stream;
    size_t in_idx = 0;
    Action action;
    std::stack<char> stack;
    do
    {
        size_t col = ActionColumn(input[in_idx]);
        size_t row = ActionRow(stack);
        action = ActionTable[row][col];
        switch (action)
        {
        case ch2ex: 
            str_stream << input[in_idx++]; 
            break;
        case ch2st:
            stack.push(input[in_idx++]);
            break;
        case st2ex:
            str_stream << stack.top();
            stack.pop();
            break;
        }
    } while (action != fin);
    return str_stream.str();
}