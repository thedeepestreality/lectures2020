#include <iostream>
#include "BSTree.h"

int main()
{
    BSTree<int> tree;
    tree.insert(10);
    tree.insert(3);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);

    tree.print();

    return 0;
}