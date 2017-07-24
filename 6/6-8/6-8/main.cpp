//
//  main.cpp
//  6-8
//
//  Created by justin fung on 7/22/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Write a single function that can be used to classify students based on criteria of your choice.  Test this function by using it in place of the extrac_fails program, and use it in the program to analyze student grades.

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

struct Student_info {
    string name;
    double final, midterm;
    vector<string> homework;
};

// 6.2.1 - working with student records
// predicate for doing all the homeworks
bool sep(const Student_info& s)
{
    return (s.name[0] >= 'a' && s.name[0] <= 'j') || (s.name[0] >= 'A' && s.name[0] <= 'J');
}

// TODO: write function that separates students according to their name,
// A-K and L-Z
vector<Student_info> separate_name(vector<Student_info>& students)
{
    // initialize vector of students k to z
    vector<Student_info> k_z;
    
    // partiiton students into a-j and k-z, return as iterator the divider
    vector<Student_info>::iterator end_j= stable_partition(students.begin(),
                                                           students.end(),
                                                           sep);
    
    // copy those with k to z
    copy(end_j,students.end(),back_inserter(k_z));
    
    // return those that didnt
    return k_z;
}



// 6.2.2.(113) - analysing the grade
// function to perform median analysis on all students
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}



// analysis function
// function to printout results of a comparision of two vectors of students according to a passed analysis function
void write_analysis(ostream& out,
                    const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& lower,
                    const vector<Student_info>& upper)
{
    cout << name << ": median(did) = " << analysis(lower) <<
    ", median(didnt) = " << analysis(upper) << endl;
}


// main
int main() {
    // initialize
    vector<Student_info> students;
    Student_info student;
    
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student))
        students.push_back(student);
    
    // separate out students that didnt do the hw
    vector<Student_info> k_z = separate_name(students);
    
    // check that both groups contain data
    if (students.empty()) {
        cout << "No students with names in A to J!" << endl;
        return 1;
    }
    
    if (k_z.empty()) {
        cout << "No students with names in K to Z!" << endl;
        return 1;
    }
    
    // do the analysis
    write_analysis(cout, "median", median_analysis, students, k_z);
    
    return 0;
}
