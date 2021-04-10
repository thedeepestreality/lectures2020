#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "../String/String.h"
#include "../Vector/Vector.h"
#include "../List/List.h"
#include "../BSTree/BSTree.h"
#include "../AVLTree/AVLTree.h"
#include <ctime>

typedef Dictionary<String, String, List> Dict;
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
    while (++counter < 10000)//(!in.eof())
    {
        Pair<String, String> curr_word;
        in >> curr_word;
        dict[curr_word._key] = curr_word._value;
    }
    std::cout << "Elapsed: " << 1000 * (double)(clock() - start) / CLOCKS_PER_SEC << "\n";

    std::cout << "Dict size: " << dict.size() << "\n";
    std::cout << "Input word to translate: ";
    String word;
    std::cin >> word;

    std::cout << "Translation: " << dict[word] << "\n";

    in.close();
    return 0;
}