// Name: Jason Liaw
// SID:  861148463
// Date: 4/20/2015

#include <iostream>
#include <stack>

#include "lab3.h"

using namespace std;

int main()
{
    TwoStackFixed<int> tsf1(10, 5);
    
    tsf1.pushStack1(0);
    tsf1.pushStack1(1);
    tsf1.pushStack1(2);
    tsf1.pushStack1(3);
    tsf1.pushStack1(4);
    // should cause a problem
    tsf1.pushStack1(5);
    
    tsf1.pushStack2(0);
    tsf1.pushStack2(1);
    tsf1.pushStack2(2);
    tsf1.pushStack2(3);
    tsf1.pushStack2(4);
    // should cause a problem
    tsf1.pushStack2(5);
    
    cout << "TwoStackFixed: ";
    tsf1.display(); cout << endl;
    
    tsf1.popStack1();
    tsf1.popStack2();
    cout << "TwoStackFixed: ";
    tsf1.display(); cout << endl;
    
    tsf1.popStack1();
    tsf1.popStack1();
    tsf1.popStack1();
    tsf1.popStack1();
    // should cause a problem
    tsf1.popStack1();
    
    tsf1.popStack2();
    tsf1.popStack2();
    tsf1.popStack2();
    tsf1.popStack2();
    // should cause a problem
    tsf1.popStack2();
    
    cout << "TwoStackFixed: ";
    tsf1.display(); cout << endl;
    
    tsf1.pushStack1(5);
    tsf1.pushStack1(4);
    tsf1.pushStack1(3);
    tsf1.pushStack1(2);
    tsf1.pushStack1(1);
    
    tsf1.pushStack2(10);
    tsf1.pushStack2(9);
    tsf1.pushStack2(8);
    tsf1.pushStack2(7);
    tsf1.pushStack2(6);
    
    cout << "TwoStackFixed: ";
    tsf1.display(); cout << endl;
    
    stack<int> stk1;
    stack<int> stk2;
    stack<int> stk3;
    stk1.push(7);
    stk1.push(6);
    stk1.push(5);
    stk1.push(4);
    stk1.push(3);
    stk1.push(2);
    stk1.push(1);
    stk1.push(0);
    showTowerStates(8, stk1, stk2, stk3);
    while(!stk3.empty())
    {
        cout << stk3.top() << endl;
        stk3.pop();
    }
    
    
    return 0;
}