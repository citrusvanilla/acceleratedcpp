//
//  main.cpp
//  4-5
//
//  Created by justin fung on 7/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "readwords.h"
#include "countwords.h"
#include "countuniquewords.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::setw;

int main() {
    // read input from std:cin using a function called 'readwords'
    vector<string> words = readwords(); // from readwords.cpp

    // count total words and print total words
    // using function 'countwords'
    vector<string>::size_type word_count = countwords(words);
    
    // count unique words and print
    // using function 'countuniquewords'
    vector<string> sortedunique = sorteduniquewords(words);
    vector<int> count = countwordbyword(words);
    
    // write out results
    cout << "There are " << word_count << " total words in your input." << endl;
    
    typedef vector<string>::size_type vec_sz;
    vec_sz size = sortedunique.size();
    
    for (vec_sz i = 0; i != size; ++ i) {
        cout << setw(6) << sortedunique[i] <<
        setw(3) << count[i] << endl;
    }
    
    return 0;
}
