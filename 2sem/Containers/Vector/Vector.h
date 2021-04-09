#pragma once
#include <exception>

template <class Type>
class Vector
{
private:
    Type* _data;
    size_t _size;
    size_t _capacity;
    static const size_t kDefCapacity = 10;
    static const double kDefMultiplier() { return 1.5; }

public:
    ~Vector()
    {
        clear();
    }

    Vector(Vector const& vec) : Vector(vec._data, vec._size) {}

    Vector& operator=(Vector const& vec)
    {
        ///TODO: implement
    }

    Vector(size_t capacity = 0) : _size(0), _capacity(capacity), _data(nullptr)
    {
        if (_capacity > 0)
            _data = new Type[_capacity];
    }

    Vector(size_t size, Type const& val) : Vector(size)
    {
        for (size_t idx = 0; idx < _size; ++idx)
            _data[idx] = val;
    }

    Vector(Type* data, size_t size) 
    {
        ///TODO: implement
    }

    struct iterator
    {
        Type* _element;

        iterator(Type* elem = nullptr) : _element(elem) {}
        Type& operator*() { return *_element; }
        Type& operator*() const { return *_element; }
        bool operator==(const iterator& it) const
        {
            return _element == it._element;
        }
        bool operator!=(const iterator& it) const
        {
            return !(*this == it);
        }
        iterator& operator++()
        {
            ++_element;
            return *this;
        }
        iterator operator++(int)
        {
            Type* tmp = _element;
            ++_element;
            return iterator(tmp);
        }
    };

    iterator push_back(Type const& val);
    
    void clear()
    {
        if (_capacity != 0)
        {
            delete[] _data;
            _size = _capacity = 0;
        }
    }

    ///TODO: implement

    //Type& operator[](int idx);
    //Type const& operator[](int idx) const;

    iterator insert(Type const& val) { return push_back(val); }
    //void resize(size_t new_size);

    iterator find(Type const& to_find);
    //iterator erase(iterator to_die);

    iterator begin() { return iterator(_data); }
    iterator end() { return iterator(_data + _size); }
};

template <class Type>
typename Vector<Type>::iterator Vector<Type>::push_back(Type const& val)
{
    if (_size == _capacity)
    {
        size_t safe_capacity = _capacity <= 1 ? kDefCapacity : _capacity;
        size_t new_capacity = safe_capacity * kDefMultiplier();
        Type* tmp_data = new Type[new_capacity];
        for (size_t idx = 0; idx < _size; ++_size)
            tmp_data[idx] = _data[idx];
        if (!_data)
            delete[] _data;
        _capacity = new_capacity;
        _data = tmp_data;
    }
    _data[_size++] = val;
    return iterator(_data + _size - 1);
}

template <class Type>
typename Vector<Type>::iterator Vector<Type>::find(Type const& to_find)
{
    for (size_t idx = 0; idx < _size; ++idx)
        if (_data[idx] == to_find)
            return iterator(_data+idx);
    return end();
}