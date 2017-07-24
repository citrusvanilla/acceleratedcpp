//
//  main.cpp
//  5-0
//
//  Created by justin fung on 7/16/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>

#include <vector>
#include <string>
#include <cctpye>

using std::vector;
using std::string;
using std::isspace;

int main(int argc, const char * argv[]) {
    
    return 0;
}

// 5.1.(75)
// predicate to determine if student has failed
bool fgrade(const Student_info& s)
{
    return grade(s) > 60;
}

// 5.1.(76)
// function to return a vector of failing students as type Student_info
// first try

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;
    
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }
    // "side effect"
    students = pass;
    
    // return value
    return fail;
}

// 5.1.1.(77)
// second try: correct but potentially slow

vector<Student_info> extrac_fails2(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    
    // invariant: elements [0,i) of students represent passing grades
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i); // there is no version of erase that operates on indices
        } else
            ++i;
    }
    return fail;
}

// 5.3.(82)
// third try: iterators but no indexing; still potentially slow
vector<Studnet_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

// 5.5.(85)
// version 4: use list instead of vector
list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}


