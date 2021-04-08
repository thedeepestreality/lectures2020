#include <iostream>
#include "Dictionary.h"
#include "../BSTree/BSTree.h"
#include "../String/String.h"
#include "../Vector/Vector.h"
#include "../List/List.h"

typedef Dictionary<String, String, List> Dict;

int main()
{
    Dict dict;

    dict["c++"] = "sucks";
    dict["windows"] = "must die";
    dict["linux"] = "is the best";

    std::cout << "windows: " << dict["windows"] << "\n";

    return 0;
}