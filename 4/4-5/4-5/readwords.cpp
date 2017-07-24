//
//  readwords.cpp
//  4-5
//
//  Created by justin fung on 7/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include "readwords.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

vector<string> readwords() {
    
    cout << "Enter your words, "
    "followed by EOF: " << endl;
    
    string word;
    vector<string> words;
    
    while (cin >> word)
        words.push_back(word);
    
    return words;
}
