//
//  Student_info.cpp
//  8-1
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

// source file for Student_info-related functions
#include "Student_info.h"
using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    // as defined in 4.2.2
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    
    read_hw(is, s.homework);    // read and store all the student's homework grades
    return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
    // as defined in 4.1.3
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
