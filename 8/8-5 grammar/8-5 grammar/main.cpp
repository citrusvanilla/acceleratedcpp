//
//  main.cpp
//  7-5 - grammar
//
//  Created by justin fung on 7/25/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Reimplement the gen_sentence function from Chapter 7 to use output iterators rather than putting the entire output in one data structure.  Test this  new version by writing programs that attach the output iterator directly to the standard ouput, and by storing the reuslts in a list<string>.


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <random>
#include <fstream> // include for reading txt files
#include <ctime>
#include <list>

using std::string;
using std::vector;
using std::istream;
using std::map;
using std::logic_error;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream; // include for reading txt files
using std::srand;
using std::list;


// grammar typedef
typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

// grammar file
string filename = "grammar.txt";


// 6.1.1.(103) - Another way to split
// fucntion to split input lines into vectors of strings
// true if arg is whitespace, false otherwise
bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    
    iter i = str.begin();
    while (i != str.end()) {
        
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        
        // find end of next word
        iter j = find_if(i, str.end(), space);
        
        // copy the characters in [i,j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}


// 7.4.4 - Selecting a random element
// returns a random integer in the range [0,n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;
    
    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}


// 7.4.2 - Reading the grammar
// read a grammar from a given input stream
Grammar read_grammar(ifstream& file)
{
    Grammar ret;
    string line;
    
    //read the input
    while (getline(file, line)) {
        
        // split the input into words
        vector<string> entry = split(line);
        
        if (!entry.empty())
            // use the category to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}


// 7.4.3 - Generating the sentence
bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");
        
        // fetch the set of possible rules
        const Rule_collection& c = it->second;
        
        // from which we select one at random
        const Rule& r = c[nrand(c.size())];
        
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}



list<string> gen_sentence(const Grammar& g)
{
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}


// 7.4.3 - Generating the sentence
// main
int main() {
    // seed random generator
    srand(time(0));
    
    // generate the sentence
    ifstream file(filename);
    list<string> sentence = gen_sentence(read_grammar(file));
    
    // write the first word, if any
    list<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
        cout << *it;
        ++it;
    }
    
    // write the rest of the words, each preceeded by a space
    while (it != sentence.end()) {
        cout << " " << *it;
        ++it;
    }
    
    cout << endl;
    return 0;
}
