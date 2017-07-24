//
//  main.cpp
//  6-6
//
//  Created by justin fung on 7/22/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  PROMPT:  "Note that the fucntion from the previous exercise and the fucnitons from 6.2.2/133 and 6/2/3/115 do the same task.  Merge these three analysis functions into a single function.

#include <iostream>


// median analysis
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}


// average analysis
double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}


// optimistic median analysis
double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}


// single analysis function
// pass a function as the second argument, page 114
// "it looks just like a function declaration"
double analysis(const vector<Student_info>& students,
                double grading_function(const Student_info&))
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grading_function);
    return median(grades);
}
