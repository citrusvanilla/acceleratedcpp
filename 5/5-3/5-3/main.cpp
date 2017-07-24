//
//  main.cpp
//  5-3
//
//  Created by justin fung on 7/18/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime> // include this header for performance measurement
#include <fstream> // include for reading txt files
#include <list>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::ifstream;
using std::list;

// 'list' or 'vector' implementation
typedef list<Student_info> student_type;
// typedef vector<Student_info> student_type;

// predicate for failing students
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
};

// function to extract failing students
student_type extract_fails(student_type& students)
{
    student_type fail;
    student_type::iterator iter = students.begin();
    
    // invariant: elements [0,i) of students represent passing grades
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

// function to read in students and grades
student_type readlines(ifstream& file, string::size_type& maxlen) {
    
    cout << "Write the records of the students as "
    "{Name} {final} {midterm} *{homeworks}, "
    "followed by E.O.F.:" << endl;
    
    student_type students;
    Student_info record;
    // string::size_type maxlen = 0;       // the length of the longest name
    
    // read and store all the students' data
    // Invariant:   students contains all the student records read so far
    //              maxlen contains the length of the longest name in students
    
    while (read(file,record)) {
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    return students;
}

// function to print student records
void printlines(student_type& s, const string::size_type& maxlen) {
    student_type::iterator iter = s.begin();
    
    
    while (iter != s.end()) {
        
        // write the name, padded on the right to maxlen + 1 characters
        cout << (*iter).name
        << string (maxlen + 1 - (*iter).name.size(), ' ');
        
        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
            << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
        
        ++iter;
    }
}

// main
int main() {
    
    // read in students and records
    ifstream file ("100.txt");
    string::size_type maxlen = 0;
    student_type students = readlines(file, maxlen);
    
    // extract failing students and measure function performance
    int start_s=clock();
    student_type fail_students = extract_fails(students);
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    
    // write the names and grades of the failures
    // printlines(fail_students, maxlen);
    
    return 0;
}
