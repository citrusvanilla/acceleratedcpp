//
//  grade.cpp
//  6-6
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//


#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

// definitions for the grade funtions from 4.1 and 4.2

double grade(double midterm, double final, double homework) { // call-by-value
    // compute FINAL grade
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm,final,median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}
