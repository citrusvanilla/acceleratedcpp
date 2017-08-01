//
//  main.cpp
//  8-0
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::domain_error;
using std::string;

// 8.1.1.(141)
// a template function that calculates a median for a vector of arithmatic types
template <class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}


// 8.1.3.(143)
// a template implementation of the 'max' function
template <class T>
T max(const T& left, const T& right)
{
    return left > right ? left : right;
}


// 8.2.2.(145)
// a template implementation of the 'find' function
template <class In, class X>
In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}


// 8.2.2.(146)
// a template implementation of the 'find' function using recursion
template <class In, class X>
In find2(In begin, In end, const X& x)
{
    if (begin == end || *begin == x)
        return begin;
    begin++;
    return find2(begin, end, x);
}


// 8.2.3.(146)
// a template implementation of the copy function
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}


// 8.2.4.(147) - sequential read-write access
//
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end) {
        if (*beg == x)
            *beg = y;
        ++beg;
    }
}


// 8.2.6.(148) - random access
// template implementation of binary search
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        
        // see which part of the range contains d; keep looking only in that part
        if (x < *mid)
            end = mid;
        else if (*mid < x )
            begin = mid + 1;
        // if we got here, then *mid == x so we're done
        else return true;
    }
    return false;
}


// 8.4.(152) - using iterators for flexibility
// a better split function using templates
inline bool space(char c) {
    return isspace(c);
}

inline bool not_space(char c) {
    return !isspace(c);
}

template <class Out>
void split(const string& str, Out os)
{
    typedef string::const_iterator iter;
    
    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);
        
        // find end of next word
        iter j = find_if(i, str.end(), space);
        
        // copy the characters in [i,j)
        if (i != str.end())
            *os++ = string(i,j);    // changed
        
        i = j;
    }
}


// main
int main(){
    return 0;
}

