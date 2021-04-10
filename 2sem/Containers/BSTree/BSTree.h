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

        size_t height() const
        {
            size_t left_h = (_left == nullptr) ? 0 : _left->height();
            size_t right_h = (_right == nullptr) ? 0 : _right->height();
            return left_h < right_h ? right_h + 1 : left_h + 1;
        }
    };
    Node* _root;
    size_t _size;
public:
    BSTree() : _root(nullptr),
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
    void print() const;
    size_t height() const 
    { 
        return _root == nullptr ? 0 : _root->height(); 
    }
    size_t size() const { return _size; }

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

    iterator erase(iterator pos);
};

template <typename Type>
void BSTree<Type>::print() const
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

template<typename Type>
typename BSTree<Type>::iterator BSTree<Type>::erase(iterator pos)
{
    Node* to_erase = pos._node;
    if (to_erase == nullptr) return pos;

    Node* replace;
    if (to_erase->left == nullptr)
        replace = to_erase->right;
    else if (to_erase->right == nullptr)
        replace = to_erase->left;
    else
    {
        replace = to_erase->right->minimum();
        if (replace->parent != to_erase)
        {
            replace->parent->left = replace->right;
            if (replace->right) replace->right->parent = replace->parent;
            replace->right = to_erase->right;
            to_erase->right->parent = replace;
        }
        replace->left = to_erase->left;
        to_erase->left->parent = replace;
    }

    if (to_erase->parent == nullptr)
        _root = replace;
    else
    {
        if (to_erase->parent->left == to_erase)
            to_erase->parent->left = replace;
        else
            to_erase->parent->right = replace;
    }

    if (replace != nullptr) replace->parent = to_erase->parent;

    to_erase->right = to_erase->left = nullptr;
    delete to_erase;
    --_size;

    return iterator(replace);
}