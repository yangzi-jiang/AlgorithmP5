//
//  main.cpp
//  p5
//
//  Created by Jiang, Yangzi on 11/30/17.
//  Copyright © 2017 Jiang, Yangzi. All rights reserved.
//
//  igraph.h: https://codeshare.io/GqXJLB
//  igraph.cpp : https://codeshare.io/5zPKPE

#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

void client(const vector<string>&);

int main() {
    string fileName;
    
    cout<< "Enter name of file containing the words: " << endl;
    cin >> fileName;
    cout << endl;
    
    // open the file
    ifstream inc;
    
    inc.open(fileName.c_str());
    if (inc.fail()) {
        cerr << "Error: Cannot open " << fileName << endl;
        exit(1);
    }
    
    int numWords;
    inc >> numWords;
    
    // Make an array for all the words, load it
    vector <string> words;
    
    string temp;
    
    for (int i = 0; i < numWords; i++){
        inc >> temp;
        words.push_back(temp);
    }

    // Construct edge set
    
    
    cout << "  Number of vertices: " << endl;
    cout << "  Number of edges: " << "xxx." << endl;
    cout << "  Number of components: " << "xxx." << endl;
    cout << "  Largest component: " << "xxx words." << endl;
    cout << "  Largest degree: " << "xxx at xxx." << endl;
    
    
    client(words);
    
    
    return 0;
}

void client (const vector<string>& setWords){
    string command;
    cout << "Command (d/i/q)? ";
    cin >> command;
    
    if (command == "d"){
        string source;
        string destination;
        
        cout << "Enter source word: ";
        cin >> source;
        
        // Need to check if source word exist?
        
        if (find(setWords.begin(), setWords.end(), source) != setWords.end()) {
            cout << "Source word not found" << endl;
            client(setWords);
        }
        
        cout << "Enter destination word: ";
        cin >> destination;
        
        if (find(setWords.begin(), setWords.end(), destination) != setWords.end()) {
            cout << "Destination word not found" << endl;
            client(setWords);
        }
        
        // determine if link exists
//        if (!link(source, destination)){
//            cout << "There is no path from " << source << " to " << destination << endl;
//            client(setWords);
//        }
        
        else{
            // get link
            cout << "The path from " << source << " to " << destination << " is " << "#" << " steps" << endl;
            
            cout << "  " << "word" << endl;
            client(setWords);
        }
    }
    
    
    if (command == "i"){
        string info;
        cout << "Enter the word you need information on: ";
        cin >> info;
        
        if (find(setWords.begin(), setWords.end(), info) != setWords.end()) {
            cout << "Word not found" << endl;
            client(setWords);
        }
        
        // need to check  if source word exist
        cout << "Degree of " << "graph" << " is " << endl;
        cout << "Neighborhood of " << "graph" << " :" << endl;
        // get neighborbodd
        
        for (int i = 0; i < 0; i++){
            cout << "  " << "word"<< endl;
        }
        
        cout << "Eccentricity of " <<  "graph" << " : " << "Ecce" << endl;
        
        client(setWords);
    }
    
    if (command == "q"){
        cout << "Thank you for playing!";
    }
    
    return;
}









