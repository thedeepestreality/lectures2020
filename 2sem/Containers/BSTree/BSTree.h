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

    void clear();
    void print();

    struct iterator
    {
        Node* _curr;
        iterator(Node* curr = nullptr) : _curr(curr) {}
        Type& operator*() const { return _curr->_data; }
        bool operator==(iterator const& it) const { return _curr == it._curr; }
        bool operator!=(iterator const& it) const { return !(*this == it); }
        iterator& operator++()
        {
            _curr = _curr->next();
            return *this;
        }
        iterator operator++(int)
        {
            Node* prev = _curr;
            _curr = _curr->next();
            return iterator(prev);
        }
    };

    iterator begin() { return iterator(_root); }
    iterator end() { return iterator(); }

    iterator insert(Type const& val);
    iterator find(Type const& to_find);
};

template <typename Type>
void BSTree<Type>::print()
{
    if (_root == nullptr)
        return;
    for (Node* curr = _root->minimum(); curr != nullptr; curr = curr->next())
        std::cout << curr->_data << " ";
    std::cout << "\n";
}

template <typename Type>
void BSTree<Type>::clear()
{
    _size = 0;
    if (_root)
        delete _root;
    _root = nullptr;
}

template <typename Type>
typename BSTree<Type>::iterator BSTree<Type>::insert(Type const& val)
{
    ++_size;
    if (_root == nullptr)
    {
        _root = new Node(val);
        return begin();
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
    return iterator(curr);
}

template <typename Type>
typename BSTree<Type>::iterator BSTree<Type>::find(Type const& to_find)
{
    Node* curr = _root;
    while (curr != nullptr)
    {
        if (curr->_data < to_find)
            curr = curr->_right;
        else if (curr->_data > to_find)
            curr = curr->_left;
        else
            return iterator(curr);
    }
    return end();
}