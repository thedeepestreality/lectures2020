#include <iostream>
#include <ctime>

class Unit
{
protected:
    const double _kBaseHealth;
    double _health;
    double _strengh;
public:
    Unit(double health, double strengh) :   _kBaseHealth(health), 
                                            _health(health), 
                                            _strengh(strengh) 
    {}
    void hit(Unit* u) const
    {
        double damage = (double)rand()/RAND_MAX * _strengh;
        u->takeDamage(damage);
    }

    void takeDamage(double const kDamage)
    {
        _health -= kDamage;
    }

    bool alive() const
    {
        return _health > 0;
    }

    void heal()
    {
        _health = _kBaseHealth;
    }

    virtual void roar() = 0;
    virtual void status() = 0;
};

class Alien : public Unit
{
public:
    Alien() : Unit(20, 25) {}

    void roar()
    {
        std::cout << "Alien  roars!\n";
    }

    void status()
    {
        std::cout << "Alien's health is " << _health << "\n";
    }
};

class Predator : public Unit
{
public:
    Predator() : Unit(25, 20) {}

    void roar()
    {
        std::cout << "Predator  roars!\n";
    }

    void status()
    {
        std::cout << "Predator's health is " << _health << "\n";
    }
};

void fight(Unit* bob, Unit* joe)
{
    std::cout << "Yet another fight!\n";
    bob->roar();
    joe->roar();
    bool coin = rand() % 2;
    Unit* left = coin ? bob : joe;
    Unit* right = coin ? joe : bob;
    while (bob->alive() && joe->alive())
    {
        left->hit(right);
        if(right->alive())
            right->hit(left);
        left->status();
        right->status();
    }
    left->alive() ? left->heal() : right->heal();
}

int main()
{
    srand(time(NULL));
    const size_t kSize = 10;
    Unit* units[kSize];
    for (size_t idx = 0; idx < kSize; ++idx)
    {
        bool flag = rand() % 2;
        units[idx] = flag ? (Unit*)new Alien : (Unit*)new Predator;
    }

    for (size_t iter = 0; iter < kSize - 1; ++iter)
    {
        size_t idx1 = rand() % kSize;
        while (!units[idx1]->alive()) 
            idx1 = rand() % kSize;

        size_t idx2 = rand() % kSize;
        while (!units[idx2]->alive()) 
            idx2 = rand() % kSize;

        fight(units[idx1], units[idx2]);
    }

    for (size_t idx = 0; idx < kSize; ++idx)
    {
        if (units[idx]->alive())
        {
            std::cout << "The winner roars: ";
            units[idx]->roar();
            break;
        }
    }

    return 0;
}