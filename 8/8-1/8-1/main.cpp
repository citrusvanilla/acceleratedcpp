//
//  main.cpp
//  8-1
//
//  Created by justin fung on 7/28/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Note that the variod analysis functions we wrote in 6.2.110 share teh same behavior,
//  they differ only in terms of the fucntions they call to calculate the final grade.  Write a tem-
//  plate function, parameterized by the type of the grading function, and use that function to
//  evaluate the grading schemes.


#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <numeric>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;
using std::ostream;


// 6.2.1.(110) - working with student records
// a predicate to check if student has completed all the homeworks
bool did_all_hw (const Student_info& s)
{
    return find(s.homework.begin(),s.homework.end(),0) == s.homework.end();
}


// 6.2.2.(113) - analyzing the grades
// auxiliary function that clarifies which version of overloaded 'grade' we want to use
double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}




// 6.2.3.(115) - grading based on average homework grade
// functions to compute average of homeworks
double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}




// 6.2.3.(116) - grading based on average homework grade
// functions to compute a median of homeworks less than full number of hws

// 4.0 - compute the median of a vector<double>
double median(vector<double> vec)
{
    // function body as defined in 4.1.1
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(), vec.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}




// quesiton 8.1, the analysis fucntions
template <class Function>
double do_analysis(const vector<Student_info>& students, Function grading_function)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grading_function);
    return median(grades);
}


// 6.2.2.(113) - analyzing the grade
// function to printout results of a comparision of two vectors of students according to a passed analysis function
void write_analysis(ostream& out,
                    const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt)
{
    cout << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}



// main
int main(int argc, const char * argv[]) {

}
