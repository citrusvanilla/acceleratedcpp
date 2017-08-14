//
//  Student_info.cpp
//  9-0 student data
//
//  Created by justin fung on 8/9/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::istream;
using std::vector;


// function definition for nonmember function 'compare'
bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}


// constructor called with no arguments
Student_info::Student_info(): midterm(0), final(0) { }


// constructor called with an input stream as an argument
Student_info::Student_info(istream& is) { read(is); }


// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();
        
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
        
        // clear the stream so that input will work for the next student
        in.clear();
    }
    
    return in;
}

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    g = ::grade(midterm, final, homework);      // added
    return in;
}
