//  igraph.h
//
//
//
//  main.cpp : https://codeshare.io/5QgK8w
//  igraph.cpp : https://codeshare.io/5zPKPE

#include <string>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(const vector<string>&);
    const vector<string>& wordlist;
    vector< vector<int> > vertices;
private:
    bool link (const string&, const string&);
    
};
