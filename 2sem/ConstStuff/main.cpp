#include <iostream>

class Dummier
{
public:
    int x;
    Dummier() = default;
    Dummier(Dummier const&)
    {
        std::cout << "Dummier copy\n";
    }
};

class Dummy
{
    Dummier const& _a;
public:
    Dummy(Dummier const& a) : _a(a)
    {
    }

    void print_dummier()
    {
        std::cout << _a.x << '\n';
    }
};

Dummy* create_dummy()
{
    Dummier dummier;
    dummier.x = 1;
    Dummy* dummy = new Dummy(dummier);
    return dummy;
}

class ConstVal
{
public:
    // Allow to change field in the const objects
    mutable bool spinlock = false;
    void magic() const
    {
        spinlock = true;
        std::cout << "Magic happened!\n";
        spinlock = false;
    }
};

int main()
{
    Dummy* dummy = create_dummy();
    dummy->print_dummier();
    delete dummy;

    const ConstVal hooray;
    hooray.magic();
    hooray.magic();
    hooray.magic();

    return 0;
}