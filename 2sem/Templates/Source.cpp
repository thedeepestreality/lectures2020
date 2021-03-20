#include <iostream>

template <class T>
struct remove_ptr
{
    typedef T type;
};

template <class T>
struct remove_ptr<T*>
{
    using type = typename remove_ptr<T>::type;
};

template <class T>
void foo(T x)
{
    typename remove_ptr<T>::type y;
    typename remove_ptr<T>::type z;
    //T y;
    //T z;
    y + z;
    //...
}

template <class T>
void foo_fail(T x)
{
    T y;
    T z;
    y + z;
    //...
}

int main()
{
    remove_ptr<int>::type x = 1;
    remove_ptr<int*>::type z = 2;
    foo(x);
    int** y = nullptr;
    foo(y);

    return 0;
}