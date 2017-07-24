//
//  main.cpp
//  6-9
//
//  Created by justin fung on 7/22/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

// main
int main() {
    // prompt and read in
    cout << "Enter some text, followed by EOF: " << endl;
    
    // initiate input and read in
    string line;
    vector<string> input;
    while(getline(cin,line))
        input.push_back(line);
    
    // append all the lines together
    string base = "";
    string output = accumulate(input.begin(), input.end(), base);
    
    // print out
    cout << "The result is: " << endl << output << endl;
    
    return 0;
}
