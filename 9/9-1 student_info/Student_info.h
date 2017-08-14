//
//  Student_info.hpp
//  9-1 student data
//
//  Created by justin fung on 8/9/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#ifndef Student_info_hpp
#define Student_info_hpp

#include <string>
#include <vector>


// 9.3.(160) Protection
// a class implementation of a student and associated info
class Student_info {
public:
    // interface goes here
    Student_info();                                         // constructor
    Student_info(std::istream&);                            // constructor
    
    double grade() const { return g; };                     // accessor function
    std::string name() const { return n; };                 // accessor function
    
    std::istream& read(std::istream&);                      // member function
    bool valid() const { return !homework.empty(); } ;      // member function

private:
    // implementation goes here
    std::string n;                                          // private data
    double midterm, final, g;                               // private data
    std::vector<double> homework;                           // private data
};


//9.3.1.(162) Accessor functions
// an example of a nonmember function
bool compare(const Student_info& x, const Student_info& y); // nonmember function


#endif
