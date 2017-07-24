//
//  main.cpp
//  7-0
//
//  Created by justin fung on 7/23/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>


using std::string;
using std::cin;
using std::cout;
using std::map;
using std::pair;
using std::endl;
using std::vector;
using std::istream;


// 7.2 - Counting words
// counting distinct words in an input
/*
int main()
{
    string s;
    map<string, int> counters; // store each word and an associated counter
    
    // read the input, keeping track of each word and how often we see it
    while (cin >> s)
        ++counters[s];
    
    // write the words and associated counts
    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end();
         ++it) {
        cout << it->first << "\t" << it -> second << endl;
    }
    return 0;
}
*/

// 7.3 - Generating a cross-reference table
// a program to indicate where each word of input occurs

// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    
    // read the net line
    while (getline(in, line)) {
        ++line_number;
        
        // break the input line into words
        vector<string> words = find_words(line);
        
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}

int main()
{
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);
    
    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
        // write the word
        cout << it->first << " occures on line(s): ";
        
        // foloowed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;       // write the first line number
        
        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            cout << ", " << *line_it;
            ++line_it;
        }
        //write a new line to separate each word from the next
        cout << endl;
    }
    
    return 0;
}




/*
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
*/
