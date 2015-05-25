// Name: Jason Liaw
// SID:  861148463
// Date: 5/11/2015

#include <iostream>
#include <utility>

using namespace std;

// Part 1
template<typename L> void selectionsort(L &l)
{
    for(typename L::iterator it1 = l.begin(); it1 != l.end(); ++it1)
    {
        typename L::iterator it2 = it1;
        for(typename L::iterator it3 = it1; it3 != l.end(); ++it3)
        {
            if(*it3 < *it2)
                it2 = it3;
        }
        swap(*it1, *it2);
    }
}

// Question 2: part b
// takes int references c and m to keep track of copies and moves
template<typename L> void selectionsort(L &l, int& c, int& m)
{
    for(typename L::iterator it1 = l.begin(); it1 != l.end(); ++it1)
    {
        typename L::iterator it2 = it1;
        for(typename L::iterator it3 = it1; it3 != l.end(); ++it3)
        {
            if(*it3 < *it2)
                it2 = it3;
        }
        swap(*it1, *it2);
        m += 3;
    }
}

// displays the contents of a container
template<typename L> void display(L &l)
{
    for(typename L::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
}
