//
//  median.cpp
//  8-1
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

// source file for the median function
#include <algorithm>        // to get the declaration of sort
#include <stdexcept>        // to get the declaration of domain_error
#include <vector>           // to get the declaration of vector

using std::domain_error;
using std::sort;
using std::vector;

// compute the median of a vector<double>
double median(vector<double> vec) { // call-by-value (copy of object is made)
    // function body as defined in 4.1.1
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(), vec.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}
