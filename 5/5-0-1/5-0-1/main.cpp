//
//  splittest.cpp
//  5-0
//
//  Created by justin fung on 7/17/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::isspace;


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


int main () {
    string s;
    
    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split(s);
        
        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
            cout << v[i] << endl;
    }
    return 0;
}

int main2() {
    string s;
    while (cin >> s)
        cout << s << endl;
    return 0;
}
