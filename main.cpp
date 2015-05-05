// Name: Jason Liaw
// SID:  861148463
// Date: 4/13/2015

#include <iostream>
#include <forward_list>
#include "lab2.h"

using namespace std;

int main()
{
    forward_list<int> lst;
    forward_list<int> lst3;
    List<int> lst2;
    int input = 0;
    
    cout << "Enter a set of integers(-1 to quit): ";
    while(input != -1)
    {
        cin >> input;
        if(input != -1)
        {
            lst.push_front(input);
            lst2.push_front(input);
        }
    }
    
    cout << "There are " << primeCount(lst) << " prime numbers." << endl;
    lst2.display();
    lst2.elementSwap(lst2, 4);
    lst2.display();
    
    lst3 = listCopy(lst, lst3);
    
    cout << "Forward List 1: ";
    for(forward_list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    
    cout << "Forward List 2: ";
    for(forward_list<int>::iterator it = lst3.begin(); it != lst3.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    
    printLots(lst, lst3); cout << endl;
    
    return 0;
}