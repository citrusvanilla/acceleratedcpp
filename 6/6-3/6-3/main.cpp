//
//  main.cpp
//  6-3
//
//  Created by justin fung on 7/21/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;





int main() {
    typedef vector<int>::size_type vec_sz;
    
    // initialize...
    vector<int> u(200000,100);
    vector<int> v;
    int start_s=clock();
    
    // method 1, dont use a library function
    // use a "iterator adapter"
    // (+) resizes once
    // (+) cleaner
    
    copy(u.begin(), u.end(), back_inserter(v));
    
    
    // method 2, dont use a library function
    // (-) resizes multiple times
    // (-) not obvious to developer
    
    /*
    vec_sz i = 0;
    while (i != u.size()) {
        v.push_back(u[i]);
        ++i;
    }
    */
    
    int stop_s=clock();
    cout << "exec time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    
    /*
    // write out results
    vec_sz j = 0;
    while (j != v.size()) {
        cout << v[j] << endl;
        ++j;
     
    }
    */
    
    return 0;
}
