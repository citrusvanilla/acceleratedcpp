//
//  main.cpp
//  8-4 implement swap
//
//  Created by justin fung on 8/1/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// chapter 8, problem 4: implement swap
// Implement the swap fucntion.  Why did we call swap rather than exchange the values of *beg and *end directly?
// Try it and see.

template <class Init>
void swap(Init& one, Init& two)
{
    Init tmp = one;
    one = two;
    two = tmp;
    
}


// 8.2.5.(148) - reversible access
// template implementation of library 'reverse', using bidirectional iterators
template <class BidirectionalIterator>
void reverse2(BidirectionalIterator begin, BidirectionalIterator end)
{
    while (begin != end) {
        --end;
        if (begin != end) {
            swap(*begin++, *end);
            
        }
    }
}

// main
int main() {
    // init vector of ints
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    
    // test out fuction on a vector of integers
    //swap(numbers[0], numbers[4]);
    reverse2(numbers.begin(),numbers.end());
    for (vector<int>::size_type i = 0; i != numbers.size(); ++i)
        cout << numbers[i] << ", ";
    cout << endl;
    //cout << "original vector is: " << numbers << endl;
    
}
