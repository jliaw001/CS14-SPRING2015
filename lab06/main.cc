// Name: Jason Liaw
// SID:  861148463
// Date: 5/11/2015

#include <iostream>
#include <list>
#include <utility>
#include <vector>

#include "lab6.h"

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    
    list<int> l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);
    l.push_back(1);
    l.push_back(8);
    l.push_back(9);
    
    vector<pair<int,int>> pv;
    pv.push_back(pair<int,int>(1,2));
    pv.push_back(pair<int,int>(3,-1));
    pv.push_back(pair<int,int>(-1,3));
    pv.push_back(pair<int,int>(0,0));
    pv.push_back(pair<int,int>(2,3));
    pv.push_back(pair<int,int>(1,2));
    pv.push_back(pair<int,int>(1,-2));
    pv.push_back(pair<int,int>(8,10));
    
    int moves = 0;
    int copies = 0;
    vector<pair<int,int>> pv2;
    pv2.push_back(pair<int,int>(10,2));
    pv2.push_back(pair<int,int>(-3,-1));
    pv2.push_back(pair<int,int>(-8,0));
    pv2.push_back(pair<int,int>(1,1));
    pv2.push_back(pair<int,int>(1,1));
    pv2.push_back(pair<int,int>(0,0));
    pv2.push_back(pair<int,int>(10,2));
    pv2.push_back(pair<int,int>(5,5));
    pv2.push_back(pair<int,int>(5,-5));
    pv2.push_back(pair<int,int>(0,0));
    pv2.push_back(pair<int,int>(10,2));
    
    cout << "Vector" << endl;
    cout << "pre:\t";
    display(v); cout << endl;
    selectionsort(v);
    cout << "post:\t";
    display(v); cout << endl;
    
    cout << endl;
    
    cout << "List" << endl;
    cout << "pre:\t";
    display(l); cout << endl;
    selectionsort(l);
    cout << "post:\t";
    display(l); cout << endl;
    
    cout << endl;
    
    cout << "Pair Vector" << endl;
    cout << "pre:\t";
    for(auto it : pv)
        cout << '(' << it.first << ',' << it.second << ") ";
    cout << endl;
    
    selectionsort(pv);
    cout << "post:\t";
    for(auto it : pv)
        cout << '(' << it.first << ',' << it.second << ") ";
    cout << endl;
    
    cout << endl;
    
    cout << "Pair Vector 2" << endl;
    cout << "pre:\t";
    for(auto it : pv2)
        cout << '(' << it.first << ',' << it.second << ") ";
    cout << endl;
    
    selectionsort(pv2, copies, moves);
    cout << "post:\t";
    for(auto it : pv2)
        cout << '(' << it.first << ',' << it.second << ") ";
    cout << endl;
    cout << copies << " copies and " << moves << " moves" << endl;
    
    
    return 0;
}