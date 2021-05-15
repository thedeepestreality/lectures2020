#pragma once
#include "FormulaNode.h"
#include "ifx2pfx.h"
#include <string>
#include <map>
#include <functional>

class Formula
{
private:
    using FN = FormulaNode;
    FN* _root;

    std::map<char, std::function<FN* (FN*, FN*)>> node_map
    {
        {'+',[](FN* left, FN* right) {return new PlusNode(left,right); }},
        {'-',[](FN* left, FN* right) {return new MinusNode(left,right); }},
        {'*',[](FN* left, FN* right) {return new MultNode(left,right); }},
        {'/',[](FN* left, FN* right) {return new DivNode(left,right); }}
    };

    FormulaNode* from_postfix(std::string const& input)
    {
        std::stack<FN*> nodes;
        for (char curr : input)
        {
            if (isdigit(curr))
            {
                nodes.push(new NumNode(curr - '0'));
                continue;
            }
            FN* node;
            FN* right = nodes.top(); nodes.pop();
            FN* left = nodes.top(); nodes.pop();
            nodes.push(node_map[curr](left, right));
        }
        return nodes.top();
    }

public:
    Formula(std::string const& input, bool is_postfix = false)
    {
        if (is_postfix)
            _root = from_postfix(input);
        else
            _root = from_postfix(infixToPostfix(input));
    }
    int calc() const { return _root->calc(); }
    std::string str() const { return _root->str(); }
    ~Formula()
    {
        delete _root;
    }
};