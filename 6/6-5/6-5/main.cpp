//
//  main.cpp
//  6-5
//
//  Created by justin fung on 7/22/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>



// a function to compute the 'optimistic median' of a student
// # hws completed may be less than all

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
