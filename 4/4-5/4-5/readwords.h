//
//  readwords.h
//  4-5
//
//  Created by justin fung on 7/15/17.
//  Copyright © 2017 justin fung. All rights reserved.
//
//  Writing headers is in 4.3 pg. 66.
//  >"header file must contain declaration of function,
//  with body of function replaced with a semicolon
//  > since we dont know if our users want to use using-declarations,
//  we omit them from header files
//  > add the #ifndef preprocessor magic to make sure the compiler
//  does not add duplicate declarations



#ifndef GUARD_readwords_h
#define GUARD_readwords_h

#include <vector>
#include <string>
std::vector<std::string> readwords();

#endif /* readwords_h */
