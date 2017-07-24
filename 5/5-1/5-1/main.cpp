//
//  main.cpp
//  5-1
//
//  Created by justin fung on 7/17/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::sort;
using std::endl;
using std::setw;

struct Rotation {
    std::vector<std::string>::size_type first;
    std::vector<std::string> text;
};

bool compareByText(const Rotation& a, const Rotation& b)
{
    return a.text[0] < b.text[0];
}

int main()
{
    // read input and store into a vector of individual words
    cout << "Enter your phrase, "
            "followed by E.O.F." << endl;
    string s;
    vector<string> input;
    while (cin >> s)
        input.push_back(s);
    
    // rotate the words and add to a vector of Rotation types
    // initiate first element of matrix
    vector<Rotation> matrix;
    Rotation tmp;
    tmp.first = 0;
    tmp.text = input;
    matrix.push_back(tmp);
    
    typedef vector<string>::size_type vec_sz;
    vec_sz size = input.size();
    
    for (vec_sz i = 1; i != size; ++i) {
        Rotation add;
        add.first = i;
        
        for (vec_sz j = i; j != size; ++j) {
            add.text.push_back(input[j]);
        }
        
        for (vec_sz k = 0; k != i; ++k) {
            add.text.push_back(input[k]);
        }
        
        matrix.push_back(add);
    }
    
    // sort the vector of texts
    sort(matrix.begin(),matrix.end(),compareByText);
    
    
    // write out a permuted index
    cout << "Your permuted index:" << endl;
    
    for (vector<Rotation>::size_type i = 0; i != matrix.size(); ++i) {
        vec_sz size = matrix[i].text.size();
        vec_sz start = size - matrix[i].first;
        
        string right1;
        string left1;
        
        for (vec_sz j = 0; j != start; ++j) {
            
            right1 += matrix[i].text[j] + " ";
        }
        
        for (vec_sz k = start; k != size; ++k) {
            left1 += matrix[i].text[k] + " ";
        }
        
        cout << setw(30)
             << left1
             << "\t"
             << right1 << endl;
    }
    
    return 0;
}
