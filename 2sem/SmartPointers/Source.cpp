#include <iostream>
#include <memory>
#include <vector>

//RAII
//Resource Allocation Is Initialization
template <class T>
class AutoPtr
//std::auto_ptr
{
    T* _ptr;
public:
    AutoPtr(T* ptr = nullptr) : _ptr(ptr) {}
    ~AutoPtr() { delete _ptr; }
};

//std::unique_ptr
template<class T>
class UniquePtr
{
    T* _ptr;
public:
    UniquePtr(T* ptr = nullptr) : _ptr(ptr) {}
    ~UniquePtr() { delete _ptr; }
    UniquePtr(UniquePtr const&) = delete;
    UniquePtr& operator=(UniquePtr const&) = delete;
    UniquePtr(UniquePtr&& up) : _ptr(up._ptr)
    {
        up._ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& up)
    {
        delete _ptr;
        _ptr = up._ptr;
        up._ptr = nullptr;
    }
};

template<class T>
struct ControlBlock
{
    T* _ptr;
    size_t _count;
    size_t _weak_count;
};

//std::shared_ptr
template<class T>
class SharedPtr
{
    T* _ptr;
    size_t* _count;
public:
    SharedPtr(T* ptr) : _ptr(ptr), _count(new int(1)) {}
    SharedPtr(SharedPtr const& sp) : _ptr(sp._ptr), _count(_count) 
    {
        ++(*_count);
    }

    ~SharedPtr()
    {
        --(*_count);
        if ((*_count) == 0)
        {
            delete _ptr;
            delete _count;
        }
    }
};

struct Dummy
{
    int val;
};

void using_unique_ptr()
{
    std::unique_ptr<int> p1(new int(1));
    std::unique_ptr<int> p2;
    p2 = std::move(p1);
    int p2_data = *p2;

    std::unique_ptr<Dummy> dummy_ptr(new Dummy());
    dummy_ptr->val = 1;

    std::vector<std::unique_ptr<int>> vec_uni_ptr;
    vec_uni_ptr.emplace_back(new int(1));

    //std::unique_ptr<int[]> p_arr(new int[10]);
}

void weak_ptr_usage()
{
    std::weak_ptr<Dummy> wp;
    {
        std::shared_ptr<Dummy> sp(new Dummy());
        wp = sp;
    }
    std::cout << wp.expired() << std::endl;
    // wp.expired() -- check if pointer is alive
    // wp.lock() -- construct and return shared_ptr
}

void f(int x)
{
    int* p = new int(1);
    if (x == 0)
        throw "zero case";
    delete p;
}

void foo(AutoPtr<int> ap)
{
    //...
}

void almost_good_f(int x)
{
    AutoPtr<int> ap(new int(1));
    foo(ap);
    if (x == 0)
        throw "zero case";
}

int banditnik(int x)
{
    if (x==0)
        throw "zero case";
    return x;
}
void bar(std::shared_ptr<int> sp, int val)
{

}

template <typename Type, typename... Args>
SharedPtr<Type> make_shared(Args&&... args)
{
    return SharedPtr<Type>(new Type(std::forward<Args>(args)));
}

void totally_good_f(int x)
{
   // std::shared_ptr<int> 
   // bar(std::shared_ptr<int>(new int(1)), banditnik(0));
    bar(std::make_shared<int>(1), banditnik(0));
    std::unique_ptr<Dummy> dup = std::make_unique<Dummy>();
    std::shared_ptr<Dummy> dsp = std::move(dup);

   // dsp.reset(); //release ownership
    // dsp.reset(ptr); //owning new ptr
}

int main()
{
    try
    {
       // f(0);
        almost_good_f(0);
    }
    catch (...)
    {
        //...
    }
    system("pause");
    return 0;
}