//
//  grade.cpp
//  9-1 student data
//
//  Created by justin fung on 8/10/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <vector>
#include <stdexcept>

using std::domain_error;
using std::vector;

#include "grade.h"
#include "median.h"

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}
