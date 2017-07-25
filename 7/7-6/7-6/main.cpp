//
//  main.cpp
//  7-6 - grammar
//
//  Created by justin fung on 7/25/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Reimplement the gen_sentence program using two vectors: One will hold the fully unwound, generated sentence, and the other will hold the rules and will be used as a stack.  Do not use any recursive calls.

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

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{

    
    // locate the rule that corresponds to word
    Grammar::const_iterator it = g.find(word);
        
    // fetch the set of possible rules
    const Rule_collection& c = it->second;
    
    // push onto a stack
    Rule_collection gstack;
    
    for (Rule_collection::const_iterator i = c.begin(); i != c.end(); ++i) {
        gstack.push_back(*i);
    }
    
    while (!gstack.empty())
    {
        Rule tmp_rule = gstack.back();
        gstack.pop_back();
        string tmp_vc;
        
        for (Rule::const_iterator j = tmp_rule.begin(); j != tmp_rule.end(); ++j) {
            tmp_vc = tmp_vc + " " + *j;
        }
        
        Grammar::const_iterator git = g.find(tmp_vc);
        
        
        // fetch the set of possible rules
        const Rule_collection& c = git->second;
        const Rule& r = c[nrand(c.size())];
        
        if (!bracketed(word)) {
            ret.push_back(word);
        //} else {
        
        //ret.push_back(
        
    }
    
    
        // from which we select one at random
        
        
        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
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
    vector<string> sentence = gen_sentence(read_grammar(file));
    
    // write the first word, if any
    vector<string>::const_iterator it = sentence.begin();
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
