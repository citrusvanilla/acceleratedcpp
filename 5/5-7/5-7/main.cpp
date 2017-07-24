//
//  main.cpp
//  5-7
//
//  Created by justin fung on 7/18/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::max;
using std::cout;
using std::endl;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}


vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an astkeris and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] +
                      string(maxlen - v[i].size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}

int main(int argc, const char * argv[]) {
    vector<string> v;
    vector<string> test = frame(v);
    
    vector<string>::size_type size = test.size();
    for (vector<string>::size_type i = 0; i != size; ++i) {
        cout << test[i] << endl;
    }
}
