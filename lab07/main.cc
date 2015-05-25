// Name: Jason Liaw
// SID:  861148463
// Date: 5/11/2015

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Function to populate and search a tree and hash table while
// dumping runtimes to output file
void runTests(vector<string>& v, set<string>& s, unordered_set<string> u, unsigned n, ofstream& fout)
{
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    auto runtime = chrono::duration_cast<std::chrono::microseconds>(end - start);
    double total_runtime = 0;
    auto runtime_treeins = chrono::duration_cast<std::chrono::microseconds>(start - start);
    auto runtime_hashins = chrono::duration_cast<std::chrono::microseconds>(start - start);
    double runtime_treefind = 0;
    double runtime_hashfind = 0;
    
    fout << n << '\t';
    fout << setprecision(4);
    for(unsigned i = 0; i < 10; ++i)
    {
        
        // runtime for inserting into a tree
        start = chrono::system_clock::now();
        for(unsigned i = 0; i < n; ++i)
            s.insert(v.at(i));
        end = chrono::system_clock::now();
        runtime = chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        runtime_treeins += runtime;
        
        // runtime for inserting into a hash table
        start = chrono::system_clock::now();
        for(unsigned i = 0; i < n; ++i)
            u.insert(v.at(i));
        end = chrono::system_clock::now();
        runtime = chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        runtime_hashins += runtime;
        
        // runtime for searching for each word through a tree
        total_runtime = 0;
        for(unsigned i = 0; i < n; ++i)
        {
            start = chrono::system_clock::now();
            s.find(v.at(i));
            end = chrono::system_clock::now();
            runtime = chrono::duration_cast<std::chrono::microseconds>(end - start);
            total_runtime += runtime.count();
        }
        runtime_treefind += total_runtime / n;
        
        // runtime for searching for each word through a hash table
        total_runtime = 0;
        for(unsigned i = 0; i < n; ++i)
        {
            start = chrono::system_clock::now();
            u.find(v.at(i));
            end = chrono::system_clock::now();
            runtime = chrono::duration_cast<std::chrono::microseconds>(end - start);
            total_runtime += runtime.count();
        }
        runtime_hashfind += total_runtime / n;
    }
    fout << runtime_treeins.count() / 10 << '\t';
    fout << runtime_hashins.count() / 10 << '\t';
    fout << runtime_treefind / 10 << '\t';
    fout << runtime_hashfind / 10;
    fout << endl;
}

// function to scramble the vector
void scrambleVector(vector<string>& v, unsigned n)
{
    for(unsigned i = 0; i < n; ++i)
        swap(v.at(rand() % n), v.at(rand() % n));
        
}

int main(int args, char* argv[])
{
    vector<string> words;
    set<string> set_words;
    unordered_set<string> uset_words;
    fstream fin(argv[1]);
    ofstream fout(argv[2]);
    srand(time(0));
    
    // Check if the files are open
    if(!fin.is_open())
    {
        cout << "Input file did not open correctly." << endl;
        exit(1);
    }
    
    if(!fout.is_open())
    {
        cout << "Output file did not open correctly." << endl;
        exit(1);
    }
    
    // Populate the vector with the words
    string input;
    while(fin >> input)
        words.push_back(input);
    
    for(unsigned i = 5000; i <= 50000; i += 5000)
    {
        runTests(words, set_words, uset_words, i, fout);
    }
    
    fin.close();
    fout.close();
    return 0;
}