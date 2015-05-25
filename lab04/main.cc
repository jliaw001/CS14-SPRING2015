// Name: Jason Liaw
// SID:  861148463
// Date: 4/27/2015

#include <iostream>
#include <queue>

#include "lab4.h"

using namespace std;

int main(int argc, char** argv)
{
    priority_queue<P, vector<P>, greater<P>> q;
    
    cout << "pre-order" << endl;
    listCoprimePairs(9, 2, 1);
    listCoprimePairs(9, 3, 1);
    
    cout << "post-order" << endl;
    listCoprimePairs2(9, 2, 1);
    listCoprimePairs2(9, 3, 1);
    
    cout << "sorted" << endl;
    listCoprimePairs3(9, 2, 1, q);
    listCoprimePairs3(9, 3, 1, q);
    print_pqueue(q);
    return 0;
}

