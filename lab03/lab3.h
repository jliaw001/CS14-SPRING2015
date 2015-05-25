// Name: Jason Liaw
// SID:  861148463
// Date: 4/20/2015

#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <stack>

using namespace std;

template <typename T> class TwoStackFixed
{
 private:
 
    // points to the first element of the array
    T* arr;
    
    // stores how much the stacks can hold
    unsigned cap1;
    unsigned cap2;
    
    // stores the current size of each stack
    unsigned size1;
    unsigned size2;
    
 public:
 
    TwoStackFixed(int size, int maxtop)
     : arr(new T[size]), cap1(maxtop), cap2(size - maxtop), size1(0), size2(0)
    {}
    
    ~TwoStackFixed()
    {
        delete[] arr;
    }
    
    void pushStack1(T value)
    {
        if(this->isFullStack1())
        {   
            cout << "Stack 1 Overflow." << endl;
            return;
        }
        
        // moves everything in the stack1 partition of the array up 1
        for(int i = size1; i > 0; --i)
            arr[i] = arr[i - 1];
        
        arr[0] = value;
        ++size1;
    }
    
    void pushStack2(T value)
    {
        if(this->isFullStack2())
        {
            cout << "Stack 2 Overflow." << endl;
            return;
        }
        
        // size of the entire array itself
        int size = cap1 + cap2;
        // moves everything in the stack2 partition of the array down 1
        for(int i = size2; i > 0; --i)
            arr[size - 1 - i] = arr[size - i];
        
        arr[size - 1] = value;
        ++size2;
    }
    
    void popStack1()
    {
        if(this->isEmptyStack1())
        {
            cout << "Stack 1 Underflow." << endl;
            return;
        }
        
        // moves everything in the stack1 partition of the array down 1
        for(int i = 0; i < size1; ++i)
            arr[i] = arr[i + 1];
        
        --size1;
    }
    
    void popStack2()
    {
        if(this->isEmptyStack2())
        {
            cout << "Stack 2 Underflow." << endl;
            return;
        }
        
        int size = cap1 + cap2;
        
        // moves everything in the stack2 partition of the array up 1
        for(int i = 1; i < size2; ++i)
            arr[size - i] = arr[size - 1 - i];
        
        --size2;
    }
    
    bool isFullStack1()
    {
        if(size1 == cap1)
            return true;
        
        return false;
    }
    
    bool isFullStack2()
    {
        if(size2 == cap2)
            return true;
        
        return false;
    }
    
    bool isEmptyStack1()
    {
        if(size1 == 0)
            return true;
            
        return false;
    }
    
    bool isEmptyStack2()
    {
        if(size2 == 0)
            return true;
            
        return false;
    }
    
    void display()
    {
        // prints first stack
        for(unsigned i = 0; i < size1; ++i)
            cout << arr[i] << ' ';
        
        cout << "| ";
            
        // prints second stack
        unsigned size = cap1 + cap2;    
        for(unsigned i = 0; i < size2; ++i)
            cout << arr[size - 1 - i] << ' ';
    }
};

template <typename T> class TwoStackOptimal
{
 private:
 
    // points to the first element of the array
    T* arr;
    
    // stores how much the array is able to hold
    unsigned cap;
    
    // stores the current size of each stack
    unsigned size1;
    unsigned size2;
    
 
 public:
 
    TwoStackOptimal(int size)
     : arr(new T[size]), cap(size), size1(0), size2(0)
    {}
    
    void pushFlexStack1(T value)
    {
        if(this->isFullStack1())
        {
            cout << "Stack Overflow." << endl;
            return;
        }
        
        // moves everything in the stack1 partition of the array up 1
        for(int i = size1; i > 0; --i)
            arr[i] = arr[i - 1];
        
        arr[0] = value;
        ++size1;
    }
    
    void pushFlexStack2(T value)
    {
        if(this->isFullStack2())
        {
            cout << "Stack Overflow." << endl;
            return;
        }

        // moves everything in the stack2 partition of the array down 1
        for(int i = size2; i > 0; --i)
            arr[cap - 1 - i] = arr[cap - i];
        
        arr[cap - 1] = value;
        ++size2;
    }
    
    void popFlexStack1()
    {
        if(this->isEmptyStack1())
        {
            cout << "Stack 1 Underflow." << endl;
            return;
        }
        
        // moves everything in the stack1 partition of the array down 1
        for(int i = 0; i < size1; ++i)
            arr[i] = arr[i + 1];
        
        --size1;
    }
    
    void popFlexStack2()
    {
        if(this->isEmptyStack2())
        {
            cout << "Stack 2 Underflow." << endl;
            return;
        }
        
        // moves everything in the stack2 partition of the array up 1
        for(int i = 1; i < size2; ++i)
            arr[cap - i] = arr[cap - 1 - i];
        
        --size2;
    }
    
    bool isFullStack1()
    {
        if(size1 + size2 == cap)
            return true;
        
        return false;
    }
    
    bool isFullStack2()
    {
        if(size1 + size2 == cap)
            return true;
        
        return false;
    }
    
    bool isEmptyStack1()
    {
        if(size1 == 0)
            return true;
        
        return false;
    }
    
    bool isEmptyStack2()
    {
        if(size2 == 0)
            return true;
        
        return false;
    }
};

// Tower of Hanoi

template <typename T> void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if(n > 0)
    {
        showTowerStates(n - 1, A, C, B);
        C.push(A.top());
        A.pop();
        cout << "Moved " << C.top() << " from peg A to C" << endl;
        showTowerStates(n - 1, B, A, C);
    }
}

#endif