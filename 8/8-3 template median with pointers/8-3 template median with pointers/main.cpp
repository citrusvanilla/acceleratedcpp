//
//  main.cpp
//  8-3 template median with pointers
//
//  Created by justin fung on 8/1/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::domain_error;
using std::endl;
using std::cout;

// 8.1.1.(141) - medians of unknown type
// a template function that accepts vectors of arithmatic types and returns an arithmatic type
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

// ch. 8, problem 3 -
// as we wlearned in 4.1.4/58, it can be expensive to return )or pass) a container by value.  Yet the median fucntion that we wrote in 8.1.1140 passes the vector by value.  Could we rewrite the median function to operate on iterators instead of passing the vector?  If we did so, what would you expect the performance impact to be?
template <class Type, class InputIterator>
Type median2(InputIterator begin, InputIterator end)
{
    if (begin == end)
        throw domain_error("median of an empty vector");
    
    sort(begin,end);
    
    int size = 0;
    
    while (begin != end) {
        ++size;
        ++begin;
    }
    
    int mid = size/2;
    
    return size % 2 == 0 ? (*(end-mid) + *(end-mid-1)) / 2 : *(end-mid);
}

template <class T, class Iterator>
T add( Iterator first, Iterator last )
{
    T temp = 0;
    while( first != last ) {
        temp += *first;
        first++;
    }
    return temp;
}

// main
int main() {
    // initiate vector
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(5);
    numbers.push_back(7);

    // call median
    cout << "median is: " << median(numbers) << endl;
    
    // "The compiler cannot deduce T; must provide with the following:
    //  median<double>(vec.begin(), vec.end())
    cout << "median is: " << median2<int>(numbers.begin(),numbers.end()) << endl;
    
    return 0;
}
