#pragma once

template <typename Type>
class List
{
public:
    struct Node
    {
        Type data;
        Node* next;
        Node(Type const& d) : data(d), next(nullptr) {}
    };

    struct iterator
    {
        Node* _node;
        iterator(Node* node = nullptr) : _node(node) {}
        Type& operator*() const
        {
            return _node->data;
        }

        bool operator==(iterator const& it)
        {
            return _node == it._node;
        }

        bool operator!=(iterator const& it)
        {
            return !(*this == it);
        }

        iterator& operator++()
        {
            _node = _node->next;
            return *this;
        }

        iterator operator++(int)
        {
            Node* tmp = _node;
            _node = _node->next;
            return iterator(tmp);
        }
    };

private:
    Node* _root;
    size_t _size;
public:
    List() :_root(nullptr), _size(0) {}

    List(Type* data, size_t size)
    {
        ///TODO: implement
    }

    List(List const& source)
    {
        ///TODO: implement
    }

    List& operator=(List const& source)
    {
        ///TODO: implement
    }

    void clear()
    {
        while (_root != nullptr)
        {
            Node* tmp = _root;
            _root = _root->next;
            delete tmp;
        }
        _size = 0;
    }
    ~List()
    {
        clear();
    }

    iterator push_back(Type const& val);
    void erase(iterator to_die_it);

    iterator begin() { return iterator(_root); }
    iterator end() { return iterator(); }

    //iterator begin() const { return const_iterator(_root); }
    //iterator end() const { return const_iterator(); }

    //void push_back(Type const& val);
    //void insert(Type const& val, iterator it_after);
    //void resize(size_t new_size);

    iterator insert(Type const& val)
    {
        return push_back(val);
    }

    iterator find(Type const& to_find);

    size_t size() const { return _size; }
};

template <class Type>
typename List<Type>::iterator List<Type>::push_back(Type const& val)
{
    if (_root == nullptr)
    {
        _root = new Node(val);
        _size = 1;
        return begin();
    }

    Node* curr = _root;
    while (curr->next != nullptr)
        curr = curr->next;
    Node* new_node = new Node(val);
    curr->next = new_node;
    ++_size;
    return iterator(new_node);
}

template <class Type>
void List<Type>::erase(iterator to_die_it)
{
    if (_root == nullptr)
        throw std::runtime_error("empty list");

    Node* to_die = to_die_it._node;
    Node* curr = _root;
    while (curr->next != to_die && curr->next != nullptr)
        curr = curr->next;

    if (curr->next != nullptr)
    {
        curr->next = to_die->next;
        delete to_die;
    }
}

template <typename Type>
typename List<Type>::iterator List<Type>::find(Type const& to_find)
{
    Node* curr = _root;
    while (curr != nullptr)
    {
        if (curr->data != to_find)
            curr = curr->next;
        else
            return iterator(curr);
    }
    return end();
}