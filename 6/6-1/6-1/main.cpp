//
//  main.cpp
//  6-1
//
//  Created by justin fung on 7/21/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::max;

// 5.8.1.(92) "framing a picture"
// rewritten in chatper 6 with iterators
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
        maxlen = max(maxlen, (*iter).size());
    return maxlen;
}

// 5.8.1.(93) "framing a picture"
// rewritten in chatper 6 with iterators
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        ret.push_back("* " + (*iter) + string(maxlen - (*iter).size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}


// 5.8.3.(95) "horizontal concatenation"
// rewritten in chatper 6 with iterators
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> ret;
    
    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;
    
    // indices to look at elements from left and right respectively
    vector<string>::const_iterator iter_i = left.begin(), iter_j = right.begin();
    
    // continue until we've seen all rows from both pictures
    while (iter_i != left.end() || iter_j != right.end()) {
        // construct new string to hold characters from both pictures
        string s;
        
        // copy a row from the left-hand side, if there is one
        if (iter_i != left.end())
            s = (*iter_i++);
        
        // pad to full width
        s += string(width1 - s.size(), ' ');
        
        // copy a row from the right-hand side, if there is one
        if (iter_j != right.end())
            s += (*iter_j++);
        
        // add s to the picture we're creating
        ret.push_back(s);
    }
    
    return ret;
}


int main() {

    return 0;
}
