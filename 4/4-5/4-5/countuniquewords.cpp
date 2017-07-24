//
//  countuniquewords.cpp
//  4-5
//
//  Created by justin fung on 7/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
#include <vector>
#include <string>

#include "countuniquewords.h"

using std::vector;
using std::string;

bool compare(const string& x, const string& y) {
    return x < y;
}

vector<string> sorteduniquewords (vector<string> vec) {
    // sort the words alphabetically using the 'compare' predicate above
    sort(vec.begin(),vec.end(),compare);
    
    // declare a new string that will hold unique elements of vec
    vector<string> output;
    
    // initialize output by adding first word of sorted vec
    output.push_back(vec[0]);
    
    // loop through the sorted vector to find unique words
    typedef vector<string>::size_type vec_sz;
    vec_sz size = vec.size();
    
    for (vec_sz i = 1; i != size; ++i){
        if (vec[i] != vec[i-1])
            output.push_back(vec[i]);
    }
    
    return output;
}

vector<int> countwordbyword(vector<string> vec) {
    // sort the words alphabetically using the 'compare' predicate above
    sort(vec.begin(),vec.end(),compare);
    
    // declare a new string that will hold counts of vec
    vector<int> output;
    
    // initialize output by adding first word count of sorted vec
    output.push_back(1);
    
    // loop through the sorted vector to count words
    typedef vector<string>::size_type vec_sz;
    vec_sz size = vec.size();
    
    int j = 0;
    for (vec_sz i = 1; i != size; ++i){
        if (vec[i] != vec[i-1]) {
            output.push_back(1);
            ++j;
        } else {
            output[j] += 1;
        }
    }

    return output;
}
