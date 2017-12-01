// igraph.cpp
//
// main.cpp : https://codeshare.io/5QgK8w
// igraph.h : https://codeshare.io/GqXJLB
//

#include "igraph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::Graph(const vector<string>& words) : wordlist(words) {
    vertices = vector< vector<int> > ();
    for (int i = 0; i < wordlist.size(); i++) {
        vertices.push_back(vector<int> ());
        for (int j = 0; j < wordlist.size(); j++) {
            if (link(wordlist[i],wordlist[j])) {
                vertices[i].push_back(j);
            }
        }
    }
}

void Graph::bfs() {
    
}

bool Graph::link (const string& w1, const string& w2) {
    int w1l = w1.length();  // length() returns unsigned length -
    int w2l = w2.length();  // cast to int to prevent underflow
    
    if (((w1l - w2l) > 1) || ((w1l - w2l) < -1)) return false;
    if (w1l == w2l) {
        bool found_diff = false;
        for (int i = 0; i < w1l; i++) {
            if (w1[i] != w2[i]) {
                if (!found_diff) found_diff = true;
                else return false;
            }
        }
        return found_diff;
    }
    
    string longer;
    string shorter;
    
    if (w1l == (w2l + 1)) {
        longer = w1;
        shorter = w2;
    }
    else if (w2l == (w1l + 1)) {
        longer = w2;
        shorter = w1;
    }
    else return false;
    
    int j = 0;
    for (int i = 0; i < shorter.length(); i++) {
        if (longer[j] != shorter[i]) {
            j++;
            if (j-i >= 2 || longer[j] != shorter[i]) {
                return false;
            }
        }
        j++;
    }
    return true;
}
