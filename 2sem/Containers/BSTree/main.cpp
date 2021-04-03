#include <iostream>
#include "BSTree.h"

int main()
{
    BSTree<int> tree;
    tree.push(10);
    tree.push(3);
    tree.push(5);
    tree.push(1);
    tree.push(2);

    tree.print();

    return 0;
}