//
//  12-0.hpp
//  
//
//  Created by justin fung on 9/26/17.
//
//

#ifndef _2_0_hpp
#define _2_0_hpp

#include <stdio.h>

class Str {
    // friend member function for output operator
    friend std::istream& operator>>(std::istream&, Str&);
    
public:
    typedef Vec<char>::size_type size_type;
    
    // default constructor; create an empty Str
    Str() { }
    
    // create a Str containing n copies of c
    Str(size_type n, char c): data(n, c) { }
    
    // create a Str from a null-terminated array of char
    Str(const char* cp) {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    
    // create a Str from teh range denoted by iterators b and e
    template <class In> Str(In v, In e) {
        std::copy(b, e, std::back_inserter(data));
    }
    
    Str& operator+=(const Str& s) {
        std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
        return *this;
    }
    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }
    size_type size() const { return data.size(); }
    
private:
    Vec<char> data;
    
    // output operator implemented in 12.3.2/216
    std::ostream& operator<<(std::ostream&, const Str&);
    
    Str operator+(const Str&, const Str&);
};

#endif /* _2_0_hpp */
