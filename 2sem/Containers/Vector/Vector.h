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

    Vector(size_t capacity = 0) : _capacity(capacity), _data(nullptr)
    {
        _size = 0;
        if (_capacity != 0)
            _data = (Type*)::operator new(_capacity*sizeof(Type));
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
            for (size_t idx = 0; idx < _size; ++idx)
                _data[idx].~Type();
            ::operator delete[](_data);
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
        _data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
        new(_data) Type(val);
        _size = 1;
        return;
    }

    if (_size == _capacity)
    {
        _capacity *= kDefMultiplier();
        Type* tmp_data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
        for (size_t idx = 0; idx < _size; ++idx)
            new(tmp_data+idx) Type(_data[idx]);
        clear();
        _data = tmp_data;
    }

    new(_data + (_size++)) Type(val);
}
