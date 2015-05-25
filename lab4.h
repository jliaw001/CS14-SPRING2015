// Name: Jason Liaw
// SID:  861148463
// Date: 4/27/2015

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> P;

// ex 1
void listCoprimePairs(int k, int m, int n)
{
    
    if(m == 2 && n == 1)
        cout << m << ' ' << n << endl;
    
    if(m == 3 && n == 1)
        cout << m << ' ' << n << endl;
        
    
    if((2 * m - n) + m <= k)
    {
        cout << 2 * m - n << " " << m << endl;
        listCoprimePairs(k, 2 * m - n, m);
    }
    
    if((2 * m + n) + m <= k)
    {
        cout << 2 * m + n << " " << m << endl;
        listCoprimePairs(k, 2 * m + n, m);
    }
    
    if((m + 2 * n) + n <= k)
    {
        cout << m + 2 * n << " " << n << endl;
        listCoprimePairs(k, m + 2 * n, n);
    }
}

// ex2
void listCoprimePairs2(int k, int m, int n)
{
    if((2 * m - n) + m <= k)
    {
        listCoprimePairs2(k, 2 * m - n, m);
        cout << 2 * m - n << " " << m << endl;
    }
    
    if((2 * m + n) + m <= k)
    {
        listCoprimePairs2(k, 2 * m + n, m);
        cout << 2 * m + n << " " << m << endl;
    }
    
    if((m + 2 * n) + n <= k)
    {
        listCoprimePairs2(k, m + 2 * n, n);
        cout << m + 2 * n << " " << n << endl;
    }
    
    if(m == 2 && n == 1)
        cout << m << ' ' << n << endl;
    
    if(m == 3 && n == 1)
        cout << m << ' ' << n << endl;
        
}

// ex3
void listCoprimePairs3(int k, int m, int n, priority_queue<P, vector<P>, greater<P>>& q)
{
    if(m == 2 && n == 1)
    {
        pair<int, int> p;
        p.first = 2;
        p.second = 1;
        q.push(p);
    }
    
    if(m == 3 && n == 1)
    {
        pair<int, int> p;
        p.first = 3;
        p.second = 1;
        q.push(p);
    }
    
    if((2 * m - n) + m <= k)
    {
        pair<int, int> p;
        p.first = 2 * m - n;
        p.second = m;
        q.push(p);
        listCoprimePairs(k, 2 * m - n, m);
    }
    
    if((2 * m + n) + m <= k)
    {
        pair<int, int> p;
        p.first = 2 * m + n;
        p.second = m;
        q.push(p);
        listCoprimePairs(k, 2 * m + n, m);
    }
    
    if((m + 2 * n) + n <= k)
    {
        pair<int, int> p;
        p.first = m + 2 * n;
        p.second = n;
        q.push(p);
        listCoprimePairs(k, m + 2 * n, n);
    }
    
}

void print_pqueue(priority_queue<P, vector<P>, greater<P>>& q)
{
    while(!q.empty())
    {
        cout << q.top().second << ' ' << q.top().first - q.top().second << endl;
        q.pop();
    }
}