//
//  grade.cpp
//  9-0 student data
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
std::string grade(double midterm, double final) {
    if (0.5 * midterm + 0.5 * final >= 0.6)
        return "P";
    else
        return "F";
        
        //return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
