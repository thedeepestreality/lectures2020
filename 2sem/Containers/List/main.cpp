#include <iostream>
#include "List.h"
#include <list>

//template <typename Type>
//std::ostream& operator<<(std::ostream& out, List<Type> const& list)
//{
//    for (auto it = list.begin(); it != list.end(); ++it)
//        out << *it << "\n";
//    return out;
//}

int main()
{
    List<int> list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << "\n";
    //std::cout << list;

    list.erase(++list.begin());

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << "\n";

    return 0;
}