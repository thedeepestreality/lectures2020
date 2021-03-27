#include <iostream>
#include "List.h"
#include <list>

int main()
{
    std::list<double>::iterator it;
    it._Ptr;
    List<int> list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << "\n";

    list.erase(++list.begin());

    for (auto it = list.begin(); it != list.end(); ++it)
        std::cout << *it << "\n";

    return 0;
}