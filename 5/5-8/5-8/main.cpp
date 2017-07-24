//
//  main.cpp
//  5-8
//
//  Created by justin fung on 7/18/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::max;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}


// hcon
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;
    
    string s;
    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new string to hold characters from both pictures
        
        
        // copy a row from the left-hand side, if there i one
        if (i != left.size())
            s = left[i++];
        
        // pad to full width
        s += string(width1 - s.size(), ' ' );
        
        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];
        
        // add s to the picture we're creating
        ret.push_back(s);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> left, right;
    left.push_back("hello this is a test");
    left.push_back("and so is this");
    
    right.push_back("also over here is one");
    right.push_back("finally this too");
    
    vector<string> ret = hcat(left, right);
    
    typedef vector<string>::size_type vec_sz;
    
    for (vec_sz i = 0; i != ret.size(); ++i) {
        cout << ret[i] << endl;
    }
    
    return 0;
}
