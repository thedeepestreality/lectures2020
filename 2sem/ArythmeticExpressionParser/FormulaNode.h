#pragma once
#include <string>

struct FormulaNode
{
    virtual int calc() const = 0;
    virtual std::string str() const = 0;
    virtual ~FormulaNode() {}
};

struct NumNode : FormulaNode
{
    int const _kNum;
    NumNode(double num) : _kNum(num) {}
    int calc() const override { return _kNum; }
    std::string str() const override
    {
        return std::to_string(_kNum);
    }
};

struct BinNode : FormulaNode
{
protected:
    FormulaNode *_left, *_right;
public:
    BinNode(FormulaNode* left,
        FormulaNode* right) : _left(left), _right(right) {}
    ~BinNode()
    {
        delete _left;
        delete _right;
    }
};

struct PlusNode : BinNode
{
    using BinNode::BinNode;
    int calc() const override
    {
        return _left->calc() + _right->calc();
    }
    std::string str() const override
    {
        return _left->str() + "+" + _right->str();
    }
};

struct MinusNode : BinNode
{
    using BinNode::BinNode;
    int calc() const override
    {
        return _left->calc() - _right->calc();
    }
    std::string str() const override
    {
        return _left->str() + "-" + _right->str();
    }
};

struct MultNode : BinNode
{
    using BinNode::BinNode;
    int calc() const override
    {
        return _left->calc() * _right->calc();
    }
    std::string str() const override
    {
        return _left->str() + "*" + _right->str();
    }
};

struct DivNode : BinNode
{
    using BinNode::BinNode;
    int calc() const override
    {
        return _left->calc() / _right->calc();
    }
    std::string str() const override
    {
        return _left->str() + "/" + _right->str();
    }
};