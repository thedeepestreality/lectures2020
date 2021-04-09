#include <iostream>
#include "Dictionary.h"
#include "../String/String.h"
#include "../Vector/Vector.h"
#include "../List/List.h"
#include "../BSTree/BSTree.h"
#include "../AVLTree/AVLTree.h"

typedef Dictionary<String, String, AVLTree> Dict;

int main()
{
    Dict dict;

    dict["c++"] = "sucks";
    dict["windows"] = "must die";
    dict["linux"] = "is the best";

    std::cout << "c++: " << dict["c++"] << "\n";
    std::cout << "windows: " << dict["windows"] << "\n";
    std::cout << "linux: " << dict["linux"] << "\n";
    std::cout << "???: " << dict["???"] << "\n";

    return 0;
}