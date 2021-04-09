#include <iostream>
#include "AVLTree.h"

int main()
{
    AVLTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    tree.print();

    std::cout << "AVLTree height: " << tree.height() << "\n";

    return 0;
}