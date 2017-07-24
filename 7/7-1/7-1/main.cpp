//
//  main.cpp
//  7-1
//
//  Created by justin fung on 7/24/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
// Extend the program from 7.2/124 to produce its ouput sorted by occurrence count. That is, the ouput should group all the words that occur once, followed by those that occur thwice, and so on.


#include <iostream>
#include <string>
#include <map>
#include <iomanip>      // std::setw

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::setw;

int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter
    int max_val = 0;
    
    // read the input, keeping tack of each word and how often we see it
    // keep track of the highest frequence value
    while (cin >> s ) {
        ++counters[s];
        if (counters[s] > max_val)
            max_val = counters[s];
    }
    
    // for 1 through the max frequency,
    // write the words and associated counts
    for (int r = 1; r <= max_val; ++r) {
        for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
            if (it->second == r)
                cout << setw(15) << it->first << setw(5) << it ->second << endl;
        }
    }
    
    return 0;
}
