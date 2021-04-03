#pragma once
#include <iostream>

template <typename Type>
class BSTree
{
private:
    struct Node
    {
        Node* _parent;
        Node* _left;
        Node* _right;
        Type _data;
        Node(Type const& data) :_parent(nullptr),
                                _left(nullptr),
                                _right(nullptr),
                                _data(data)
        {}

        ~Node()
        {
            if (_left) delete _left;
            if (_right) delete _right;
        }

        Node* minimum()
        {
            Node* curr = this;
            while (curr->_left != nullptr)
                curr = curr->_left;
            return curr;
        }

        Node* next()
        {
            if (_right != nullptr)
                return _right->minimum();
            Node* par = _parent;
            Node* curr = this;
            while (par != nullptr)
            {
                if (curr == par->_left)
                    break;
                curr = par;
                par = par->_parent;
            }
            return par;
        }
    };
    Node* _root;
    size_t _size;
public:
    BSTree() :  _root(nullptr),
                _size(0)
    {}
    ~BSTree()
    {
        clear();
    }
    BSTree(BSTree const& source)
    {
        ///TODO: implement
    }
    BSTree& operator=(BSTree const& source)
    {
        ///TODO: implement
    }

    void push(Type const& val);
    void clear()
    {
        _size = 0;
        if (_root)
            delete _root;
        _root = nullptr;
    }

    void print()
    {
        if (_root == nullptr)
            return;
        for (Node* curr = _root->minimum(); curr != nullptr; curr = curr->next())
            std::cout << curr->_data << " ";
        std::cout << "\n";
    }
};

template <typename Type>
void BSTree<Type>::push(Type const& val)
{
    ++_size;
    if (_root == nullptr)
    {
        _root = new Node(val);
        return;
    }
    Node* curr = _root;
    Node* par;
    do
    {
        par = curr;
        curr = (val < curr->_data) ? curr->_left : curr->_right;
    } while (curr != nullptr);
    curr = new Node(val);
    curr->_parent = par;
    //SPECIAL FOR KIRILL:
    // *((val < par->_data) ? (&par->_left) : (&par->_right)) = curr;
    // (val < par->_data) ? par->_left = curr : par->_right = curr;
    if (val < par->_data)
        par->_left = curr;
    else
        par->_right = curr;
}