//
//  main.cpp
//  9-0 student data
//
//  Created by justin fung on 8/10/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "median.h"
#include "grade.h"

using namespace std;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store the data
    while (record.read(cin)) {                           // changed
        maxlen = max(maxlen, record.name().size());      // changed
        students.push_back(record);
    }
    
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    
    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i].name()   // this and the next line changed
        << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double final_grade = students[i].grade();   // changed
            cout << letter_grade(final_grade) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    
    return 0;
}
