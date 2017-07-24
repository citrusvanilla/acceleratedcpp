//
//  main.cpp
//  5-11
//
//  Created by justin fung on 7/19/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
// In text processing it is sometimes useful to know whether a word has any ascenders or descnders.  Ascenders are the parts of lower case...

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

using std::list;
using std::string;
using std::max;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;

typedef list<string>::size_type list_sz;


// name of file containing words here, in same directory
string filename = "dictionary.txt";


// function for reading in data from a file
list<string> readfromfile () {
    cout << "Searching for file..." << endl;
    ifstream file(filename);
    
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


// boolean for ascenders
bool ascender(string& s) {
    return (s.find_first_of("bdfhklt") != string::npos);
}


// boolean for descenders
bool descender(string& s) {
    return (s.find_first_of("gjpqy") != string::npos);
}


// function for sussing out the ascenders and descenders
void findscenders (list<string>& dic, list<string>& asc, list<string>& des, string& s) {
    
    // iterator for the dictionary
    list<string>::iterator iter = dic.begin();
    
    // check for ascenders and descenders and move if necessary
    // if neither, check for new longest length and adjust if necessary
    while (iter != dic.end()) {
        if (ascender(*iter)) {
            asc.push_back(*iter);
            iter = dic.erase(iter);
        }
        else if (descender(*iter)) {
            des.push_back(*iter);
            iter = dic.erase(iter);
        }
        else {
            if (max(s.size(),(*iter).size()) == (*iter).size()) {
                s = (*iter);
            }
            ++iter;
        }
    }
}


// fucntion for printing out some information about the ascenders and descenders
void statistics(const list<string>& dic, const list<string>& asc,
                const list<string>& des, const string& s) {
    
    list_sz dic_size = dic.size();          // dictionary size
    list_sz asc_size = asc.size();          // ascenders size
    list_sz des_size = des.size();          // descenders size
    string::size_type length = s.size();    // longest non-scender size
    
    
    // output stats
    cout << "There are " << dic_size + asc_size + des_size << " words total." << endl;
    cout << "There are " << asc_size << " ascenders." << endl;
    cout << "There are " << des_size << " descenders." << endl;
    cout << "There are " << dic_size << " non-scenders." << endl;
    cout << "The longest non-scender is \"" << s << "\" at " << length << " characters." << endl;
}


// main
int main(int argc, const char * argv[]) {
    // initialize list of ascenders and descenders,
    // and a maximum non-scender.
    // read in dictionary of words and return a list of strings
    list<string> dictionary = readfromfile();
    list<string> ascenders;
    list<string> descenders;
    string maximum = "";
    
    // add to ascenders and descenders,
    // edit dictionary to include non-scenders
    // edit maximum non-scender.
    findscenders (dictionary, ascenders, descenders, maximum);
    
    // print out results of the whole affair
    int start_s=clock();
    statistics (dictionary, ascenders, descenders, maximum);
    int stop_s=clock();
    cout << "exec time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    
    return 0;
}
