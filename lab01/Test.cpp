#include <iostream>
#include <list>

using namespace std;

list<int> mergeList(list<int> a, list<int> b);
list<int> mergeSortList(list<int> a, list<int> b);
void listRotate(list<int> &a, int n);
void display(list<int> a);

int main()
{
    list<int> l1;
    list<int> l2;
    list<int> l3;
    list<int> l4;
    int input = 0;
    
    do
    {
        cout << "Enter an integer for the first list(-1 to stop): ";
        cin >> input;
        if(input >= 0)
            l1.push_back(input);
            
    } while(input != -1);
    
    input = 0;
    do
    {
        cout << "Enter an integer for the second list(-1 to stop): ";
        cin >> input;
        if(input >= 0)
            l2.push_back(input);
            
    } while(input != -1);
    
    cout << "List 1: ";
    display(l1); cout << endl;
    cout << "List 2: ";
    display(l2); cout << endl;
    
    l3 = mergeList(l1, l2);
    l4 = mergeSortList(l1, l2);
    
    cout << "Merged List: ";
    display(l3); cout << endl;
    
    cout << "Merged Sorted List: ";
    display(l4); cout << endl;
    
    listRotate(l1, 3);
    cout << "Rotated List: ";
    display(l1); cout << endl;
    return 0;
}

void display(list<int> a)
{
    for(list<int>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';
}

list<int> mergeList(list<int> a, list<int> b)
{
    list<int> newList;
    list<int>::iterator it1 = a.begin();
    list<int>::iterator it2 = b.begin();
    
    while(it1 != a.end() && it2 != b.end())
    {
        newList.push_back(*it1);
        newList.push_back(*it2);
        ++it1;
        ++it2;
    }
    
    while(it1 != a.end())
    {
        newList.push_back(*it1);
        ++it1;
    }
    
    while(it2 != b.end())
    {
        newList.push_back(*it2);
        ++it2;
    }
    
    return newList;
}

list<int> mergeSortList(list<int> a, list<int> b)
{
    list<int> newList;
    list<int>::iterator it1 = a.begin();
    list<int>::iterator it2 = b.begin();
    
    while(it1 != a.end() && it2 != b.end())
    {
        if(*it1 < *it2)
        {
            newList.push_back(*it1);
            ++it1;
        }
        else
        {
            newList.push_back(*it2);
            ++it2;
        }
    }
    
    while(it1 != a.end())
    {
        newList.push_back(*it1);
        ++it1;
    }
    
    while(it2 != b.end())
    {
        newList.push_back(*it2);
        ++it2;
    }
    
    return newList;
}

void listRotate(list<int> &a, int n)
{
    list<int>::iterator it = a.begin();
    
    for(int i = 0; i < n; ++i)
    {
        a.push_back(*it);
        ++it;
        a.pop_front();
    }
}