//
//  median.cpp
//  10-2 median on vector OR array
//
//  Created by justin fung on 8/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include "median.hpp"
#include <vector>

using std::vector;
using std::domain_error;


// 8.1.1.(141)
// a template function that calculates a median for a vector of arithmatic types
template <class T, class Iterator>
T median(Iterator begin, Iterator end)
{
    if (begin == end)
        throw domain_error("median of an empty container");
    
    vector<T> temp;
    
    for ( ; begin != end; ++begin)
        temp.push_back(*begin);
    
    sort(temp.begin(),temp.end());
    
    size_t mid = temp.size() / 2;
    
    T ret = (temp.size() % 2 == 0)
    ? (temp[mid] + temp[mid- 1]) / 2
    : temp[mid];
    
    return ret;
    
}
