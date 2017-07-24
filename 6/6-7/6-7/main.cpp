//
//  main.cpp
//  6-7
//
//  Created by justin fung on 7/22/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  PROMPT:  The portion of the grading analysis proram from 6.2.1 that read and classified student records depending on whether they did (or did not) do all the homework is similar to the problem we solved in extract_fails.  Write a function to handle this subproblem.

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

struct Student_info {
    double final, midterm;
    vector<string> homework;
};

// 6.2.1 - working with student records
// predicate for doing all the homeworks
bool did_all_hw(const Student_info& s)
{
    return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

// TODO: write function that separates students according to whether they did or did not do the homework
vector<Student_info> separatedidnt(vector<Student_info>& students)
{
    // initialize vector of students that didnt finish hw
    vector<Student_info> didnt;
    
    // partiiton students into those that did and didnt, return as iterator the divider
    vector<Student_info>::iterator end_did = stable_partition(students.begin(),
                                                              students.end(),
                                                              did_all_hw);
    
    // copy those that didnt into didnt vector
    copy(end_did,students.end(),back_inserter(didnt));
    
    // return those that didnt
    return didnt;
}


// main
int main() {
    // initialize
    vector<Student_info> did;
    Student_info student;
    
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student))
        did.push_back(student);
    
    // separate out students that didnt do the hw
    vector<Student_info> didnt = separatedidnt(students);
    
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
    
    return 0;
}
