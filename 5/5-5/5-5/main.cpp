//
//  main.cpp
//  5-5
//
//  Created by justin fung on 7/18/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Write a function named center(const vector<string>&) that returns a picture in which all the ines of the original picture are padded out to their full width and the padding is as evenly divided as possible between the left and right sides of the picture.  What are the properties of pictures for which such a function is useful?  How can you tell whether a given picture has those properties?


#include <iostream>
#include <vector>
#include <string>
#include <locale>   // isalpha

using std::vector;
using std::string;
using std::max;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isalpha;

// 5.8.1.(92) "framing a picture"
// helper fucntion for checking width input
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

// 5.8.1.(93) "framing a picture"
// frame a vector of strings so that lines are of equal size
vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    // write the top border
    ret.push_back(border);
    
    // write each interior row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] +
                      string(maxlen - v[i].size(), ' ') + " *");
    }
    
    // write the bottom border
    ret.push_back(border);
    return ret;
}

// function for prompting user, reading in lines to a vector
// and returning the vector
vector<string> readlines() {
    // prompt user for text
    cout << "Write a block of lines, "
            "followed by EOF:" << endl;
    
    // initialize vector of strings
    // read lines into the vector
    vector<string> ret;
    string line;
    while(getline(cin,line))
        ret.push_back(line);
    
    // return the vector
    return ret;
}

// function for printing out lines of a vector of strings,
// row-by-row
void printlines(const vector<string>& s) {
    for (vector<string>::size_type i = 0; i != s.size(); ++i) {
        cout << s[i] << endl;
    }
}

// the function in question
// takes a picture of left-aligned text and returns a picture of center-aligned text
vector<string> center(const vector<string>& s) {
    // initiate empty vector and push top border onto it
    vector<string> ret;
    ret.push_back(s[0]);
    
    // capture the width of the picture
    typedef string::size_type str_sz;
    str_sz picturewidth = s[0].size();
    
    // loop through all lines containing text
    // invariant: i denotes number of lines in input we have visited
    for (vector<string>::size_type i = 1; i != s.size()-1; ++i) {
        // initiate new line with front border
        string newline = "*";
        
        // find the last character in the original string
        str_sz k = 0;
        for (str_sz j = 0; j != picturewidth; ++j) {
            if (isalpha(s[i][j]))
                k = j;
        }
        
        // find the offset needed in the front of the text
        // rounds down for cases that are not perfectly even
        // add 'offset' spaces to new line
        int offset = (picturewidth - k) / 2;
        newline += string(offset, ' ');
        
        // add original text to new line
        for (str_sz j = 2; j <= k; ++j) {
            newline += s[i][j];
        }
        
        // add spaces and border to the end
        newline += string(picturewidth-k-1-offset,' ');
        newline += "*";
        
        ret.push_back(newline);
    }
    
    // put the bottom border back on the new picture and return
    ret.push_back(s[s.size()-1]);
    return ret;
}

// main
int main() {
    // prompt user and read lines into vector
    vector<string> text = readlines();
    
    // frame the input
    vector<string> framed_text = frame(text);
    
    // center the input
    vector<string> centered_text = center(framed_text);
    
    // print out lines
    printlines(centered_text);
    
    return 0;
}
