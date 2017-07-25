//
//  main.cpp
//  7-3
//
//  Created by justin fung on 7/24/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  The cross-reference program from 7.3/126 could be improved:  As it stands, ifa  word occurs more than once on the same input line, the program will report that line multiple times.  Chance the code so that it detects multiple occurrences of the same line number and inserts the line number only once.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using std::map;
using std::vector;
using std::string;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::ostringstream;

// 6.1.1 - Another way to split
// method for spliting a string by whitespace, returns a vector of strings
bool space(char c) // true if the argument is whitespace, false otherwise
{
    return isspace(c);
}

bool not_space(char c) // false if the argument is whitespace, true otherwise
{
    return !isspace(c);
}

vector<string> split(const string& str) // function
{
    typedef string::const_iterator iter;
    vector<string> ret;
    
    
    iter i = str.begin();
    while (i != str.end()) {
        
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        
        // find end of the next word
        iter j = find_if(i, str.end(), space);
        
        // copy the characers in [i,j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}


// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;
    
    // read the next line
    while (getline(in, line)) {
        ++line_number;
        
        // break the input line into words
        vector<string> words = find_words(line);
        
        
        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
            
            // if seeing the word for the first time, append the line number
            if (ret.find(*it) == ret.end()) {
                ret[*it].push_back(line_number);
            }
            
            // if the word exist, but the line number does not, append the line number
            if (find(ret[*it].begin(),ret[*it].end(), line_number) == ret[*it].end()) {
                ret[*it].push_back(line_number);
            }
        }
        
    }
    
    return ret;
}

// main
int main() {
    
    int lineLength = 50;
    
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);
    
    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        ostringstream outputStream;
        
        // write the word
        outputStream << it->first << " occurs on line(s): ";
        
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        outputStream << *line_it;   // write the first line number
        ++line_it;
        
        // write the rest of the line nubmers, if any
        while (line_it != it->second.end()) {
            outputStream << ", " << *line_it;
            ++line_it;
        }
        
        // Break outputStream into multiple lines with max width of lineLength.
        string outputLine = outputStream.str();
        for (string::size_type i = 0; i != outputLine.size(); ++i ) {
            if (i % lineLength == 0) {
                cout << endl;
            }
            cout << outputLine[i];
        }
        
        // write a new line to separate each word from the next
        cout << endl;
    }
    return 0;
}
