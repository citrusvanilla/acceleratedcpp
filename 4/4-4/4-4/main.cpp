//
//  main.cpp
//  4-4
//
//  Created by justin fung on 7/13/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int get_width(double n) {
    return log10(n) + 1;
}

int main() {
    double max = 1000.0;
    
    for (double i = 1.0; i <= max; ++i) {
        cout << setw(get_width(max))
        << i
        << setw(get_width(max * max) + 1)
        << i * i
        << endl;
    }
    
    return 0;
}
