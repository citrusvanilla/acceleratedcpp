//
//  grade.hpp
//  8-1
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double,double, const std::vector<double>&);
double grade(const Student_info&);

#endif
