// Name: Jason Liaw
// SID:  861148463
// Date: 4/13/2015

#ifndef LAB2_H
#define LAB2_H

#include <forward_list>

using namespace std;

template <typename Type> struct Node
{
    Type data;
    Node<Type> *next;
    Node(Type data)
     : data(data), next(0)
    {}
};

template <typename Type> class List
{
private:
    Node<Type> *head;
    Node<Type> *tail;
public:
    // Default Constructor
    List()
     : head(0), tail(0)
    {}
    
    // Destructor
    // ~List();
    
    // Pushes elements to the front of the list
    void push_front(Type data)
    {
        Node<Type> *temp = new Node<Type>(data);
        temp->next = head;
        head = temp;
        
        if(tail == 0)
            tail = head;
    
    }
    
    // Displays elements in the list
    void display() const
    {
        Node<Type> *current;
        for(current = head; current != 0; current = current->next)
            cout << current->data << ' ';
        
        cout << endl;
    }
    
    // Swaps elements at pos and pos + 1
    List<Type> elementSwap(List<Type> lst, int pos)
    {
        if(head == 0)
            return lst;
        
        Node<Type> *current = lst.head;
        
        if(pos == 0)
        {
            Node<Type> *next = current->next;
            current->next = next->next;
            next->next = current;
            head = next;
        }
        
        // navigate the current pointer to node
        // right before pos
        for(int i = 0; i < pos - 1; ++i)
        {
            current = current->next;
            // checks if node is out of bounds of the list
            // or if node is the last member of the list
            // or if node is the second to last member
            if(current == 0 || current->next == 0 || current->next->next == 0)
                return lst;
        }
        
        // This node pointer refers to the node with position pos
        Node<Type> *pos1 = current->next;
        Node<Type> *pos2 = pos1->next;
        
        // Set the node at pos - 1 next value to node at pos + 1
        current->next = pos2;
        
        // Set the node at pos to point towards node after pos + 1
        pos1->next = pos2->next;
        
        // Set the node at pos + 1 to point back to the node at pos
        pos2->next = pos1;
        
        return lst;
    }
};

//Exercise 1
int primeCount(forward_list<int> lst);
bool isPrime(int i );

//Exercise 3
template<typename Type> forward_list<Type> listCopy(forward_list<Type> L, forward_list<Type> P)
{
    for(typename forward_list<Type>::iterator it = L.begin(); it != L.end(); ++it)
        P.push_front(*it);
    
    return P;
}

//Exercise 4
template<typename Type> void printLots(forward_list<Type> L, forward_list<int> P)
{
    // counter variable to keep track of position in L
    int counter = 0;
    
    // iterator to keep track of position in P
    forward_list<int>::iterator it = P.begin();
    
    // loop to print out only values within L specified by integers in P
    for(typename forward_list<Type>::iterator it2 = L.begin(); it2 != L.end(); ++it2)
    {
        if(*it == counter)
        {
            cout << *it2;
            ++it;
        }
        ++counter;
    }
}

#endif