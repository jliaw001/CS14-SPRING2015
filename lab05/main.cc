// Name: Jason Liaw
// SID:  861148463
// Date: 5/4/2015

#include <iostream>

#include "lab5.h"

using namespace std;

int main()
{
    BST<int> tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(60);
    tree.insert(10);
    tree.insert(40);
    tree.insert(20);
    tree.insert(70);
    tree.insert(35);
    tree.insert(45);
    
    cout << "Part 1" << endl;
    tree.minCover();
    tree.displayMinCover();
    
    cout << "Part 2" << endl;
    tree.findSumPath(80);
    
    cout << "Part 3" << endl;
    tree.vertSum();
    
    return 0;
}