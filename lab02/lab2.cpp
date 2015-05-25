// Name: Jason Liaw
// SID:  861148463
// Date: 4/13/2015

#include <iostream>
#include "lab2.h"

// Exercise 1
int primeCount(forward_list<int> lst)
{
    if(lst.empty())
        return 0;
    
    if(isPrime(lst.front()))
    {
        lst.pop_front();
        return primeCount(lst) + 1;
    }
    
    lst.pop_front();
    return primeCount(lst);
}

bool isPrime(int i)
{
    // special case for 1
    if(i == 1)
        return false;
    
    // checks if i is divisible by anything
    for(int j = 2; j < i; ++j)
    {
        // not prime if an evenly divisble integer was found
        if(i % j == 0)
            return false;
    }
    
    return true;
}

// template<typename Type> void printLots(forward_list<Type> L, forward_list<int> P)
// {
//     // counter variable to keep track of position in L
//     int counter = 0;
    
//     // iterator to keep track of position in P
//     forward_list<int>::iterator it = P.begin();
    
//     // loop to print out only values within L specified by integers in P
//     for(typename forward_list<Type>::iterator it2 = L.begin(); it2 != L.end(); ++it2)
//     {
//         if(*it == counter)
//         {
//             cout << *it2;
//             ++it;
//         }
//         ++counter;
//     }
// }