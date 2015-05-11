// Name: Jason Liaw
// SID:  861148463
// Date: 5/4/2015

#ifndef BST_H
#define BST_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <vector>
#include <math.h>

using namespace std;

#define nil 0

//#define Value int
template <typename Value>
class BST
{
    class Node
    {
    public:
        Node* left;
        Node* right;
        Value value;
        bool selected;
        bool discovered;
        Node(const Value v = Value())
         : left(nil), right(nil), value(v), selected(false), discovered(false)
        {}
        
        
        Value& content()
        {
            return value;
        }
        
        bool isInternal()
        {
            return left != nil && right != nil;
        }
        
        bool isExternal()
        {
            return left != nil || right != nil;
        }
        
        bool isLeaf()
        {
            return left == nil && right == nil;
        }
        
        // returns the height of the subtree rooted at this node
        int height()
        {
            if(this->isLeaf())
                return 0;
            
            if(this->isInternal())
            {
                int leftHeight = this->left->height();
                int rightHeight = this->right->height();
                
                if(leftHeight > rightHeight)
                    return 1 + leftHeight;
                
                return 1 + rightHeight;
            }
            
            if(this->isExternal())
            {
                if(this->left != nil)
                    return 1 + this->left->height();
                
                if(this->right != nil)
                    return 1 + this->right->height();
            }
        }
        
        // returns the size of the subtree rooted at this node
        int size()
        {
            if(this->isLeaf())
                return 1;
            
            if(this->isInternal())
            {
                int leftSize = this->left->size();
                int rightSize = this->right->size();
                
                return 1 + leftSize + rightSize;
            }
            
            if(this->isExternal())
            {
                if(this->left != nil)
                    return 1 + this->left->size();
                
                if(this->right != nil)
                    return 1 + this->right->size();
            }
            
            return -1;
        }
    };
    
    // const Node* nil;
    Node* root;
    int count;
    
public:
    // size of the overall tree.
    int size()
    {
        if(root == 0)
            return 0;
            
        return root->size();
    }
    
    bool empty()
    {
        return size() == 0;
    }
    
    void print_node(const Node* n)
    {
        cout << n->content();
    }
    
    // search for a Value in the BST and return true if it was found.
    bool search(Value x)
    {
        if(root == 0)
            return false;
            
        return search(x, root);
    }
    
    // Helper function for search
    bool search(Value x, Node* n)
    {
        if(n->content() == x)
            return true;
        
        if(n->isLeaf())
            return false;
            
        if(n->isInternal())
        {
            if(search(x, n->left) || search(x, n->right))
                return true;
            
            return false;
        }
        
        if(n->isExternal())
        {
            if(n->left != 0)
                return search(x, n->left);
            
            if(n->right !=0)
                return search(x, n->right);
        }
        
        return false;
    }
    
    // Traverse and print the tree one Value per line in preorder.
    void preorder() const
    {
        if(root == 0)
            return;
        
        preorder(root);    
    }
    
    // Helper function for preorder()
    void preorder(Node* n) const
    {
        if(n != 0)
            cout << n->content() << endl;
        
        if(n->left != 0)
            preorder(n->left);
            
        if(n->right != 0)
            preorder(n->right);
    }
    
    // Traverse and print the tree one Value per line in postorder.
    void postorder() const
    {
        if(root == 0)
            return;
        
        postorder(root);
    }
    
    // Helper function for postorder()
    void postorder(Node* n) const
    {
        if(n->left != 0)
            postorder(n->left);
        
        if(n->right != 0)
            postorder(n->right);
        
        if(n != 0)
            cout << n->content() << endl;
    }
    
    // Traverse and print the tree one Value per line inorder.
    void inorder() const
    {
        if(root == 0)
            return;
        
        inorder(root);
    }
    
    // Helper function for inorder()
    void inorder(Node* n) const
    {
        if(n->left != 0)
            inorder(n->left);
        
        if(n != 0)
            cout << n->content() << endl;
        
        if(n->right != 0)
            inorder(n->right);
    }
    
    // returns reference to the value field of the n-th Node.
    Value& operator[](int n)
    {
        if(this->empty())
        {
            cout << "Invalid index." << endl;
            exit(0);
        }

        if(n >= this->size())
        {
            cout << "Invalid index." << endl;
            exit(0);
        }
        
        vector<Value> v;
        
        storeNum(v, root);
        return v.at(n);
    }
    
    // Helper function for overloaded [] operator
    void storeNum(vector<Value>& v, Node* n)
    {
        if(n->left != 0)
            storeNum(v, n->left);
            
        if(n != 0)
            v.push_back(n->content());
            
        if(n->right != 0)
            storeNum(v, n->right);
    }
    
    // lab5 ex1
    void minCover()
    {
        DFS(root);
    }
    
    Node* getChild(Node* x)
    {
        if(x->isInternal())
            return x->left;
        
        if(x->isExternal())
        {
            if(x->left != 0)
                return x->left;
            
            if(x->right != 0)
                return x->right;
        }
        
        return 0;
    }
    
    void DFS(Node* x)
    {
        x->discovered = true;
        if(x->left != 0)
        {
            if(x->left->discovered == false)
            {
                DFS(x->left);
                if(x->left->selected == false)
                    x->selected = true;
            }
        }
        
        if(x->right != 0)
        {
            if(x->right->discovered == false)
            {
                DFS(x->right);
                if(x->right->selected == false)
                    x->selected = true;
            }
        }
    }
    
    void displayMinCover()
    {
        int x = 0;
        displayMinCover(root, x);
        cout << endl;
        cout << x << endl;
    }
    
    void displayMinCover(Node* n, int& x)
    {
        if(n->left != 0)
            displayMinCover(n->left, x);
        
        if(n != 0 && n->selected == true)
        {
            cout << n->content() << " ";
            ++x;
        }
        
        if(n->right != 0)
            displayMinCover(n->right, x);
    }
    
    // lab5 ex2
    void findSumPath(int sum)
    {
        int buffer[10] = {};
        findSumPath(root, sum, buffer);
        cout << endl;
    }
    
    void findSumPath(Node* n, int sum, int buffer[])
    {
        if(sum == 0)
            return;
        
        if(n->left != 0)
        {
            findSumPath(n->left, sum - n->content(), buffer);
        }
        
        if(n->right != 0)
        {
            findSumPath(n->right, sum - n->content(), buffer);
        }
        
        if(sum - n->content() >= 0)
            cout << n->content() << ' ';
    }
    
    // lab5 ex3
    void vertSum()
    {
        map<int, int> m;
        vertSum(root, 0, m);
        for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
            cout << it->second << ' ';
        
        cout << endl;
    }
    
    void vertSum(Node *n, int hd, std::map<int, int>& m)
    {
        if(n == 0)
            return;
        
        m[hd] += n->content();
        
        if(n->left != 0)
            vertSum(n->left, hd - 1, m);
        
        if(n->right != 0)
            vertSum(n->right, hd + 1, m);
    }
    
    
    BST()
     : root(nil), count(0)
    {}
    
    void insert(Value X)
    {
        root = insert(X, root);
    }
    
    Node* insert(Value X, Node* T)
    {
        if(T == nil)
            T = new Node(X);
            
        else if(X < T->value)
            T->left = insert(X, T->left);
        
        else if(X > T->value)
            T->right = insert(X, T->right);
        
        else
            T->value = X;
        
        return T;
    }
    
    
    void remove(Value X)
    {
        root = remove(X, root);
    }
    
    Node* remove(Value X, Node*& T)
    {
        if(T != nil)
        {
            if(X > T->value)
                T->right = remove(X, T->right);
            
            else if(X < T->value)
                T->left = remove(X, T->left);
            
            else
            {
                if(T->right != nil)
                {
                    Node* x = T->right;
                    while(x->left != nil)
                        x = x->left;
                    
                    T->value = x->value;
                    T->right = remove(T->value, T->right);
                }
                
                else if(T->left != nil)
                {
                    Node* x = T->left;
                    while(x->right != nil)
                        x = x->right;
                    
                    T->value = x->value;
                    T->left = remove(T->value, T->left);
                }
                
                else
                {
                    delete T;
                    T = nil;
                }
            }
        }
        
        return T;
    }
};

#endif