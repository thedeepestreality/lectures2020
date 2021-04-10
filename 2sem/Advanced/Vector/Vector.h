#pragma once

namespace Advanced {
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
        Vector(size_t size = 0);
        Vector(size_t size, Type const& val);
        Vector(Vector const& vec) : Vector(vec._data, vec._size) {}
        ~Vector() { clear(); }

        Vector& operator=(Vector const& vec)
        {
            ///TODO: implement
        }

        Vector(Type* data, size_t size)
        {
            ///TODO: implement
        }

        void reserve(size_t new_capacity);
        void clear();

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

        ///TODO: implement

        //Type& operator[](int idx);
        //Type const& operator[](int idx) const;

        iterator push_back(Type const& val);

        iterator insert(Type const& val) { return push_back(val); }
        //void resize(size_t new_size);

        iterator find(Type const& to_find);
        //void erase(iterator to_die);

        iterator begin() { return iterator(_data); }
        iterator end() { return iterator(); }

        size_t size() const { return _size; }
    };

    template <class Type>
    Vector<Type>::Vector(size_t size) : _size(size), _capacity(size), _data(nullptr)
    {
        _data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
        for (size_t idx = 0; idx < _size; ++idx)
            new(_data + idx) Type;
    }

    template <class Type>
    Vector<Type>::Vector(size_t size, Type const& val) : _size(size), _capacity(size), _data(nullptr)
    {
        if (_capacity != 0)
        {
            _data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
            for (size_t idx = 0; idx < _size; ++idx)
                new(_data + idx) Type(val);
        }
    }

    template <class Type>
    void Vector<Type>::reserve(size_t new_capacity)
    {
        if (new_capacity > _capacity)
        {
            Type* tmp_data = reinterpret_cast<Type*>(::operator new(new_capacity * sizeof(Type)));
            for (size_t idx = 0; idx < _size; ++idx)
                new(tmp_data + idx) Type(_data[idx]);
            size_t prev_size = _size;
            clear();
            _data = tmp_data;
            _size = prev_size;
            _capacity = new_capacity;
        }
    }

    template <class Type>
    typename Vector<Type>::iterator Vector<Type>::push_back(Type const& val)
    {
        if (_size == _capacity)
        {
            size_t safe_capacity = _capacity <= 1 ? kDefCapacity : _capacity;
            reserve(safe_capacity * kDefMultiplier());
        }

        new(_data + (_size++)) Type(val);
        return iterator(_data + (_size - 1));
    }

    template <class Type>
    void Vector<Type>::clear()
    {
        if (_capacity != 0)
        {
            for (size_t idx = 0; idx < _size; ++idx)
                _data[idx].~Type();
            ::operator delete[](_data);
            _size = _capacity = 0;
        }
    }

    template <class Type>
    typename Vector<Type>::iterator Vector<Type>::find(Type const& to_find)
    {
        for (size_t idx = 0; idx < _size; ++idx)
            if (_data[idx] == to_find)
                return iterator(_data + idx);
        return end();
    }
}