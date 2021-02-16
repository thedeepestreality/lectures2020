#include <iostream>
#include <exception>

int VAZHNA = 1;

void lvl_0()
{
    std::cout << "LVL_0 STARTED\n";
    if (VAZHNA == 0)
        throw 0;
    std::cout << "LVL_0 ENDED\n";
}

void lvl_1()
{
    std::cout << "LVL_1 STARTED\n";
    lvl_0();
    if (VAZHNA == 1)
        throw "fail";
    std::cout << "LVL_1 ENDED\n";
}

void lvl_2()
{
    std::cout << "LVL_2 STARTED\n";
    try
    {
        lvl_1();
    }
    catch (int err_num)
    {
        std::cout << "Shit happened with code ";
        std::cout << err_num << '\n';
        throw;
    }
    catch (const char* error)
    {
        std::cout << "Shit happened with message ";
        std::cout << error << '\n';
        throw std::runtime_error(error);
    }
    std::cout << "LVL_2 ENDED\n";
}

void lvl_3()
{
    std::cout << "LVL_3 STARTED\n";
    try {
        lvl_2();
    }
    catch (std::exception err)
    {
        std::cout << "Shit happened with err message ";
        std::cout << err.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Some shit happend\n";
    }
    std::cout << "LVL_3 ENDED\n";
}

int main()
{
    lvl_3();
    return 0;
}