#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "../String/String.h"
#include "../Vector/Vector.h"
#include "../List/List.h"
#include "../BSTree/BSTree.h"
#include "../AVLTree/AVLTree.h"
#include "../../Advanced/Vector/Vector.h"
#include <ctime>

template <class T>
using AVector = Advanced::Vector<T>;
typedef Dictionary<String, String, Vector> Dict;
const char* filename = "dictionary-ru.txt";

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cout << "failed to open file\n";
        return -1;
    }
    
    Dict dict;
    clock_t start = clock();
    size_t counter = 0;
    Pair<String, String> curr_word;
    while (!in.eof())
    {
        in >> curr_word;
        //dict[curr_word._key] = curr_word._value;
       // dict.insert(curr_word);
        dict.insert(std::move(curr_word));
    }
    std::cout << "Elapsed: " << 1000 * (double)(clock() - start) / CLOCKS_PER_SEC << "\n";

    std::cout << "Dict size: " << dict.size() << "\n";
    std::cout << "Input word to translate: ";
    String word;
    //std::cin >> word;
    start = clock();
    for (int i=0;i<1000;++i)
        String const& it = dict["ark"];
    std::cout << "Elapsed: " << 1000 * (double)(clock() - start) / CLOCKS_PER_SEC << "\n";
    
    std::cout << "Translation: " << dict["ark"] << "\n";

    in.close();
    return 0;
}