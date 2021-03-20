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
    ~Vector();
    Vector(Vector const& vec) : Vector(vec._data, vec._size) {}
    Vector& operator=(Vector const& vec);

    Vector();
    Vector(size_t capacity);
    Vector(Type* data, size_t size);

    Type& operator[](int idx);
    Type operator[](int idx) const;

    void push_back(Type& const val);
    void erase(size_t idx);
    void insert(Type& const val, size_t idx_after);

    void resize(size_t new_size);
    void clear();
    bool find(Type& const to_find, Type& result);
};

template <class Type>
void Vector<Type>::push_back(Type& const val)
{
    if (_capacity == 0)
    {
        _capacity = kDefCapacity;
        _data = new Type[_capacity];
        _data[0] = val;
        _size = 1;
        return;
    }

    if (_size == _capacity)
    {
        _capacity *= kDefMultiplier;
        Type* tmp_data = new Type[_capacity];
        for (size_t idx = 0; idx < _size; ++_idx)
            tmp_data[idx] = _data[idx];
        delete[] _data;
        _data = tmp_data;
    }

    tmp_data[_size++] = val;
}

template <class Type>
void Vector<Type>::erase(size_t erase_idx)
{
    if (erase_idx >= _size)
        throw std::out_of_range();

    for (size_t idx = erase_idx; idx < _size - 1; ++idx)
        _data[idx] = _data[idx + 1];

    --_size;
}