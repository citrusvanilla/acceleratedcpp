//
//  main.cpp
//  7-9
//
//  Created by justin fung on 7/26/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  (difficult) The implementation of nrand in 7.4.4.(135) will not work for arguments greate
//  than RAND_MAX.  Usually, this restriction is no problem, because RAND_MAX is often the larg-
//  est possible integer anyway.  Nevertheless, there are implementations under which
//  RAND_MAX is much smaller than the largest possible integer.  For example it is not uncom-
//  mon for  RAND_MAX to be 32767 (2^15 - 1) and the largest possible integer to be 2147483647
//  (2^31 - 1).  Reimplement nrand so that is works well for all values of n.


#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::srand;


// 7.4.4 - Selecting a random element

// returns a random integer in the range [0,n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;
    
    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}

// main
int main() {
    // seed random generator
    srand(time(0));
    
    // prompt for number
    cout << "Upper bound of range for random integer: " ;
    int number;
    cin >> number;
    
    // generate random int
    int ret = nrand(number);
    
    // write out result
    cout << "Random integer is: " << ret << endl;
    cout << RAND_MAX;
    
    return 0;
}
