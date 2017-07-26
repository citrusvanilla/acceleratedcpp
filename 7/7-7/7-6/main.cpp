//
//  main.cpp
//  7-7
//
//  Created by justin fung on 7/23/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Change the driver for the cross-reference program so that it writes line if there i only one line and lines otherwise.

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


// 5.6.(88)
// taking strings apart

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    
    // invariant: we have processed character [original value of i,i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all sapces
        while (i != s.size() && isspace(s[i]))
            ++i;
        
        // find end of next word
        string_size j = i;
        
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;
        
        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j-i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}


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
    // Prompt for input
    cout << "Enter some words, followed by EOF:" << endl;
    
    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);
    
    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        
        // check number of unique elements in xref
        int size = 1;
        for (vector<int>::const_iterator iter = it->second.begin() + 1; iter != it->second.end(); ++iter) {
            if (*iter != *(iter-1))
                ++size;
        }
        
        // write word, and
        // "line" if length  == 1, else "lines"
        if (size > 1) {
            cout << "\"" << it->first << "\"" << " occurs on lines: ";
        } else {
            cout << "\"" << it->first << "\"" << " occurs on line: ";
        }
        
        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;       // write the first line number
        ++line_it;
        
        // write the rest of the line numbers, if any
        while (line_it != it->second.end()) {
            
            // check for non-duplicity of line numbers
            if (*line_it != *(line_it-1))
                cout << ", " << *line_it;
            
            ++line_it;
        }
        
        //write a new line to separate each word from the next
        cout << endl;
    }
    
    return 0;
}
