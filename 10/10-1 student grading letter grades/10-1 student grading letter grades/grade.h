//
//  grade.hpp
//  9-0 student data
//
//  Created by justin fung on 8/10/17.
//  Copyright © 2017 justin fung. All rights reserved.
//


#ifndef GUARD_grade_h
#define GUARD_grade_h

// `grade.h'

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::string letter_grade(double grade);

#endif
