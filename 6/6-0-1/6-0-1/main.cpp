//
//  main.cpp
//  6-0-1
//
//  Created by justin fung on 7/20/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
// TODO: write "read" function

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;



struct Student_info {
    string name;
    double final, midterm;
    vector<double> homework;
};


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


// 6.2.2.(113) - analysing the grade
// function to perform median analysis on all students
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
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

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
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

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
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
    cout << name << ": median(did) = " << analysis(did) <<
                    ", median(didnt) = " << analysis(didnt) << endl;
}


// 6.2.1.(114) - working with student records
// main
int main() {
    vector<Student_info> did, didnt;
    Student_info student;
    
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    
    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }
    
    // do the analysis
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
    
    return 0;
}
