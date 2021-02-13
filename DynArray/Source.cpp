#include <iostream>

struct DynArrayStruct
{
    int* data;
    size_t size;
};

void init(DynArrayStruct& arr, const size_t kSize)
{
    arr.size = kSize;
    arr.data = new int[arr.size];
}

class DynArray
{
private:
    int* _data;
    size_t _size;

    inline void checkIdx(size_t const kIdx)
    {
        if (kIdx >= _size)
            throw "out of bounds";
    }

public:
    //void init(const size_t kSize)
    //{
    //    _size = kSize;
    //    _data = new int[_size];
    //}
    DynArray(size_t const kSize)
    {
        std::cout << "Ya rodilsia!\n";
        _size = kSize;
        _data = new int[_size];
    }

    DynArray()
    {
        _size = 0;
        _data = nullptr;
    }

    ~DynArray()
    {
        std::cout << "Ya pagib!\n";
        if (_size != 0)
            delete[] _data;
    }

    size_t getSize()
    {
        return _size;
    }

    //Variant 1
    int getAt(size_t const kIdx)
    {
        checkIdx(kIdx);
        return _data[kIdx];
    }

    void setAt(size_t const kIdx, int const kVal)
    {
        checkIdx(kIdx);
        _data[kIdx] = kVal;
    }

    //Variant 2
    int& at(size_t const kIdx)
    {
        checkIdx(kIdx);
        return _data[kIdx];
    }
};

void dummy_func()
{
    DynArray dyn_arr(3);
    //Variant 1
    std::cout << "Variant 1:\n";
    size_t const kSize = dyn_arr.getSize();
    for (size_t idx = 0; idx < kSize; ++idx)
        dyn_arr.setAt(idx, idx);
    for (size_t idx = 0; idx < kSize; ++idx)
        std::cout << dyn_arr.getAt(idx) << "\n";

    //Variant 2
    std::cout << "Variant 2:\n";
    for (size_t idx = 0; idx < kSize; ++idx)
        dyn_arr.at(idx) = idx;
    for (size_t idx = 0; idx < kSize; ++idx)
        std::cout << dyn_arr.at(idx) << "\n";
}

int main()
{
    DynArrayStruct arr_struct;
    init(arr_struct, 3);

    arr_struct.size = 5;

    for (size_t idx = 0; idx < arr_struct.size; ++idx)
        arr_struct.data[idx] = idx;

    //DynArray dyn_arr;
    dummy_func();
    return 0;
}