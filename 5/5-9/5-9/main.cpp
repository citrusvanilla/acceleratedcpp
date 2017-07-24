//
//  main.cpp
//  5-9
//
//  Created by justin fung on 7/18/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <locale>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::isupper;


int main() {
    // prompt for input
    cout << "Enter a bunch of shit here, followed by EOF: " << endl;
    
    // initiate empty vectors for lowercase and uppercase words
    vector<string> lowercase;
    vector<string> uppercase;
    
    // read in input
    vector<string> input;
    string word;
    
    // separate according to capitalization of first letter
    while (cin >> word)
        if (isupper(word[0])) {
            uppercase.push_back(word);
        } else {
            lowercase.push_back(word);
        }
    
    // print out
    cout << "Uppercase words are: ";
    
    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i != uppercase.size(); ++i) {
        cout << uppercase[i] + " ";
    }
    
    cout << endl << "Lowercase words are: ";
    for (vec_sz i = 0; i != lowercase.size(); ++i) {
        cout << lowercase[i] + " ";
    }
    cout << endl;
        
    return 0;
}
