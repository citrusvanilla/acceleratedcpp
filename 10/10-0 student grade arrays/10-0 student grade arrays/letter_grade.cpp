//
//  letter_grade.cpp
//  10-0 student grade arrays
//
//  Created by justin fung on 8/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include "letter_grade.h"
#include <string>


std::string letter_grade(double grade)
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
