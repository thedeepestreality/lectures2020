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
    static const double kDefMultiplier = 1.5;

public:
    ~Vector()
    {
        clear();
    }
    Vector(Vector const& vec) : Vector(vec._data, vec._size) {}
    Vector& operator=(Vector const& vec);

    Vector();
    Vector(size_t capacity) : _capacity(capacity)
    {
        _size = 0;
        if (_capacity != 0)
            _data = ::operator new(_capacity*sizeof(Type));
    }

    Vector(Type* data, size_t size);

    Type& operator[](int idx);
    Type const& operator[](int idx) const;

    void push_back(Type& const val);
    void erase(Type* to_die);
    void insert(Type& const val, Type* ptr_after);

    void resize(size_t new_size);
    void clear()
    {
        ///TODO: check validity!!!
        if (_capacity != 0)
        {
            for (size_t idx = 0; idx < _size; ++idx)
                _data[idx].~Type();
            ::operator delete[](void*)_data;
        }
    }
    Type* find(Type& const to_find);
};

template <class Type>
void Vector<Type>::push_back(Type& const val)
{
    if (_capacity == 0)
    {
        _capacity = kDefCapacity;
        _data = ::operator new(_capacity * sizeof(Type));
        new(_data) Type(val);
        _size = 1;
        return;
    }

    if (_size == _capacity)
    {
        _capacity *= kDefMultiplier;
        Type* tmp_data = ::operator new(_capacity * sizeof(Type));
        for (size_t idx = 0; idx < _size; ++_idx)
            new(tmp_data+idx) Type(_data[idx]);
        clear();
        _data = tmp_data;
    }

    new(_data + (_size++)) Type(val);
}

template <class Type>
void Vector<Type>::erase(Type* to_die)
{
    int erase_idx = to_die - _data;
    if (erase_idx >= _size || erase_idx < 0)
        throw std::out_of_range();

    for (size_t idx = erase_idx; idx < _size - 1; ++idx)
    {
        _data[idx].~Type();
        new(_data + idx) Type(_data[idx + 1]);
    }
    _data[_size-1].~Type();

    --_size;
}