//
//  grade.cpp
//  9-0 student data
//
//  Created by justin fung on 8/10/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <vector>
#include <stdexcept>
#include <string>
#include "grade.h"
#include "median.h"

using std::domain_error;
using std::vector;
using std::string;


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

// 10.3.(178) initializing arrays of character pointers
// a function that returns a letter grade corresponding to a number grade
string letter_grade(double grade)
{
    // range posts for numeric grades
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };
    
    // names for the letter grades
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };
    
    // compute the number of grades given the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
    
    // given a numeric grade, find and return the associated letter grade
    for (size_t i = 0; i < ngrades; ++i) {
        if (grade >= numbers[i])
            return letters[i];
    }
    
    return "?\?\?";
}
