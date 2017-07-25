//
//  main.cpp
//  7-2
//
//  Created by justin fung on 7/24/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Extend the program in 4.2.3/64 to assign letter grades by ranges... The output should list how many students fall into each category

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setprecision;
using std::domain_error;
using std::streamsize;
using std::istream;
using std::map;
using std::setw;

// student info type
struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

// predicate for sorting by name
bool compare(const Student_info& x , const Student_info& y)
{
    return x.name < y.name;
}

// fucntions for reading in student info
istream& read_hw(istream& in, vector<double>& hw) {
    // as defined in 4.1.3
    if (in) {
        // get rid of previous contents
        hw.clear();
        
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);
        
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s) {
    // as defined in 4.2.2
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    
    read_hw(is, s.homework);    // read and store all the student's homework grades
    return is;
}

// fucntion for computing the median
// compute the median of a vector<double>
double median(vector<double> vec) { // call-by-value (copy of object is made)
    // function body as defined in 4.1.1
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    
    sort(vec.begin(), vec.end());
    
    vec_sz mid = size/2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// functions for computing grades
// definitions for the grade funtions from 4.1 and 4.2

double grade(double midterm, double final, double homework) { // call-by-value
    // compute FINAL grade
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

string grade(const Student_info& s) {
    double value = grade(s.midterm, s.final, s.homework);
    string a = "A";
    string b = "B";
    string c = "C";
    string d = "D";
    string f = "F";
    
    if (value >= 90 && value <= 100) {
        return a;
    } else if (value >= 80 && value < 90) {
        return b;
    } else if (value >= 70 && value < 80) {
        return c;
    } else if (value >= 60 && value < 70) {
        return b;
    } else {
        return f;
    }
}


// main
int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store all the records, and find the length of the longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    // initiate a associative container
    map<string,vector<Student_info> > bygrade;
    
    
    // loop to compute grade and place student in correct part of the map
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        string final_grade = grade(students[i]);
        bygrade[final_grade].push_back(students[i]);
    }
    
    // loop to print out results
    cout << "GRADES:" << endl;
    
    for (map<string,vector<Student_info> >::const_iterator it = bygrade.begin();
         it != bygrade.end();
         ++it) {
        cout << setw(2) << it->first << ": ";
        
        for (vector<Student_info>::const_iterator j = it->second.begin();
             j != it->second.end(); ++j)
            cout << j->name << " ";
        
        cout << endl;
    }
    
    return 0;
}
