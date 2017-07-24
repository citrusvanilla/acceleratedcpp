//
//  main.cpp
//  4-2
//
//  Created by justin fung on 7/13/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Write a program to calculate the squares of int values up to 100.  The program should
//  write two columns: the first lists teh value; the second conatins the square of that value.  Use
//  setw(described above) to manage the output so that the values line up in columns.
#include <iostream>
#include <iomanip>      // std::setw

using std::cout;
using std::endl;
using std::setw;


int main(int argc, const char * argv[]) {
    // generate output in list
    // page 31.
    // for (init-statement condition; expression) statement
    
    double max = 1000;
    double max1 = max;
    double max_sq = max*max;
    int len_minor = 0;
    int len_major = 0;
    
    
    while (max1 > 0) {
        ++len_minor;
        max1 /= 10;
    }
    
    while (max_sq > 0) {
        ++len_major;
        max_sq /= 10;
    }
    
    for (int i = 1; i != max + 1; ++i) {
        // output i and output the square on teh same line
        cout << setw(len_minor + 1)
             << i << setw(len_major + 1) << (i * i) << endl;
    }
    
    return 0;
}
