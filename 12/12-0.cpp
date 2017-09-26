//
//  12-0.cpp
//  
//
//  Created by justin fung on 9/26/17.
//
//

#include "12-0.hpp"

Str operator+(const Str&s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}
