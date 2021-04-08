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
    struct iterator;

    ~Vector()
    {
        clear();
    }

    Vector(Vector const& vec) : Vector(vec._data, vec._size) {}

    Vector& operator=(Vector const& vec)
    {
        ///TODO: implement
    }

    Vector(size_t size = 0) : _size(size), _capacity(size), _data(nullptr)
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

    void push_back(Type const& val);
    
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

    //void insert(Type& const val, iterator it_after);
    //void resize(size_t new_size);

    //iterator find(Type& const to_find);
    //void erase(iterator to_die);

    //iterator begin();
    //iterator end();
};

template <class Type>
void Vector<Type>::push_back(Type const& val)
{
    if (_capacity <= 1)
    {
        _capacity = kDefCapacity;
        _data = new Type[_capacity];
        _data[0] = val;
        _size = 1;
        return;
    }

    if (_size == _capacity)
    {
        _capacity *= kDefMultiplier();
        Type* tmp_data = new Type[_capacity];
        for (size_t idx = 0; idx < _size; ++idx)
            tmp_data[idx] = _data[idx];
        clear();
        _data = tmp_data;
    }

    _data[_size++] = val;
}
