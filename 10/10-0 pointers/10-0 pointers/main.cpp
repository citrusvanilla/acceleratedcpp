//
//  main.cpp
//  10-0 pointers
//
//  Created by justin fung on 8/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int x = 5;

    // p points to x
    int* p = &x;
    cout << "x = " << x << endl;
    
    // change th value of x through p
    *p = 6;
    cout << "x = " << x << endl;
    
    return 0;
}
