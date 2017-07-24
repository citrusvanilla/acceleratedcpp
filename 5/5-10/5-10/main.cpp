//
//  main.cpp
//  5-10
//
//  Created by justin fung on 7/19/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
// "Palindrowmes are words that are spelled the same right to left as left to right.
// Write a program to find all the palindromes in a dictionary.
// Next, find the longest palindrome."

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // include for reading txt files
#include <list>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::getline;
using std::list;
using std::max;

// name of file containing words here, in same directory
string filename = "words.txt";

// function returning whether or not the word is a palindrome
bool palindrome(const string& str)
{
    bool ret = true;
    string::size_type length = str.size();
    int f_idx = 0;
    int b_idx = str.size() - 1;
    
    // condition on length of string (even/odd)
    // iterate front and back indicies so long as letters are equivalent
    // if not, set 'ret' to false
    if (length % 2 == 0) {
        while ((b_idx - f_idx > 0) && ret == true) {
            if (str[f_idx] == str[b_idx]) {
                ++f_idx;
                --b_idx;
            } else {
                ret = false;
            }
        }
    }
    else {
        while (b_idx - f_idx > 1 && ret == true) {
            if (str[f_idx] == str[b_idx]) {
                ++f_idx;
                --b_idx;
            } else {
                ret = false;
            }
        }
    }
    return ret;
}

// input from a file funtion
list<string> readfromfile () {
    cout << "Searching for file..." << endl;
    ifstream file (filename);
    
    // report file open success
    if (file.is_open()) {
        cout << "File successfully open!" << endl;
        //file.close();
    } else {
        cout << "Error opening file.  Try again." << endl;
    }
    
    // read file line by line into a vector and return
    list<string> ret;
    string word;
    while (getline(file,word)) {
        // find length of longest name
        ret.push_back(word);
    }
    return ret;
}

void palindrome_stats(const list<string>& vec) {
    list<string>::const_iterator iter = vec.begin();
    list<string>::const_iterator liter = vec.begin(); // iterator pointing to longest palindrome
    string::size_type maxlen = 0;
    int num_pal = 0;
    int num_reg = 0;
    
    // check for palindrome and length
    while (iter != vec.end()) {
        if (palindrome(*iter)) {
            ++num_pal;
            if ((*iter).size() > maxlen) {
                maxlen = (*iter).size();
                liter = iter;
            }
        } else {
            ++num_reg;
        }
        ++iter;
    }
    
    // output stats
    cout << "There are " << num_pal + num_reg << " words total." << endl;
    cout << "There are " << num_pal << " palindromes." << endl;
    cout << "There are " << num_reg << " non-palindromes." << endl;
    cout << "The longest palindrome is \"" << (*liter) << "\" at " << maxlen << " characters." << endl;
}

// main
int main(int argc, const char * argv[]) {
    
    // initialize vector of words from a file
    list<string> words = readfromfile();
    
    // output palindrome stats of the file
    palindrome_stats(words);
    
    return 0;
}
