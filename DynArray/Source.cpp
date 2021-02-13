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
    size_t _size;
    int* _data;
    //SomeClass obj;
    size_t const _kMaxSize = 200;

    inline void checkIdx(size_t const kIdx) const
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

    //Constructor with arguments
    explicit DynArray(size_t const kSize) : _size(kSize),
                                            _data(new int[_size]),
                                            _kMaxSize(100)
    {
        std::cout << "Ya rodilsia!\n";
    }

    DynArray(size_t const kSize, int const kToFill)
    {
        std::cout << "Ya rodilsia!\n";
        _size = kSize;
        _data = new int[_size];
        for (size_t idx = 0; idx < _size; ++idx)
            _data[idx] = kToFill;
    }

    DynArray(size_t const kSize, int values[])
    {
        std::cout << "Ya rodilsia!\n";
        _size = kSize;
        _data = new int[_size];
        for (size_t idx = 0; idx < _size; ++idx)
            _data[idx] = values[idx];
    }

    //Default constructor
    DynArray()
    {
        _size = 0;
        _data = nullptr;
    }
    //DynArray() = default;
    //DynArray() = delete;

    //Copy constructor
    DynArray(DynArray const& source) : DynArray(source._size, source._data)
    {
        std::cout << "Copy constructor\n";
    }

    ~DynArray()
    {
        std::cout << "Ya pagib!\n";
        if (_size != 0)
            delete[] _data;
    }

    size_t getSize() const
    {
        getAt(2);
        return _size;
    }

    //Variant 1
    int getAt(size_t const kIdx) const
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
    // For const objects
    int at(size_t const kIdx) const
    {
        std::cout << "I'm const\n";
        checkIdx(kIdx);
        return _data[kIdx];
    }

    // For not const objects
    int& at(size_t const kIdx)
    {
        std::cout << "I'm not const\n";
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
    
    //HACKERMAN STUFF (USE WISELY (BETTER NOT USE AT ALL))
  /*  ((size_t*)&dyn_arr)[0] = 2;
    ((int**)&dyn_arr)[1][0] = 3;
    
    std::cout << "HACKERMAN!!11:\n";
    std::cout << dyn_arr.getSize() << "\n";
    std::cout << dyn_arr.at(0) << "\n";*/
}

void explicit_example(DynArray arr)
{

}

int main()
{
    DynArrayStruct arr_struct;
    init(arr_struct, 3);

    arr_struct.size = 5;

    for (size_t idx = 0; idx < arr_struct.size; ++idx)
        arr_struct.data[idx] = idx;

    DynArray dyn_arr;
    dummy_func();

    explicit_example(DynArray(3));

    DynArray arr(3);
    //...fill(arr)
    DynArray arr_copy = arr; //DynArray arr_copy(arr); //DynArray arr_copy = DynArray(arr);
    //DynArray arr_copy;
    //arr_copy = arr;

    DynArray const const_arr(3);

    std::cout << const_arr.getSize() << "\n";
    const_arr.at(1);

    return 0;
}