//
//  main.cpp
//  9-1 student data
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

using namespace std;


#include <iostream>

#include "Student_info.h"

using namespace std;

int main() {
    try {
        Student_info record;
        cout << record.grade();
    } catch (domain_error e) {
        cout << e.what() << endl;
    }
    
    cout << 'hello';
    return 0;
}
