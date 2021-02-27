#include <iostream>

class Singleton
{
    static bool created;
    Singleton() = default;
public:
    void speak()
    {
        std::cout << "Are ya winnig son?\n";
    }

    static Singleton create()
    {
        if (created)
            throw std::exception("already created");
        created = true;
        return Singleton();
    }

    ~Singleton()
    {
        created = false;
    }
};

bool Singleton::created = false;

int main()
{
    Singleton s = Singleton::create();
    s.speak();

    // Here comes the exception
    Singleton s1 = Singleton::create();

    return 0;
}