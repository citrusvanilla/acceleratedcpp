//
//  vec_objects.hpp
//  11-0
//
//  Created by justin fung on 9/25/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#ifndef vec_objects_hpp
#define vec_objects_hpp

#include <stdio.h>
#include <iostream>
#include <memory>

template <class T> class Vec {
public:
    // types
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    
    // constructor
    Vec() { create(); }
    // "The explicit keyword tells the compiler to use the constructor
    // only in contexts in which the user expressly invokes the constructor,
    // and not otherwise.
    explicit Vec(std::size_t n, const T& val = T()) { create(n, val); }
    
    // copy constructor
    Vec(const Vec& v) { create(v.begin(), v.end()); }  // copy constructor
    
    // assignment operator
    Vec& operator=(const Vec&);
    
    // destructor
    ~Vec() { uncreate(); }
    
    // size and index
    size_type size() const { return avail - data; }
    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
    
    // functions to return iterators
    iterator begin() { return data; }               // added
    const_iterator begin() const { return data; }   // added
    
    iterator end() { return avail; }                // added
    const_iterator end() const { return avail; }    // added
    
    // op: push back
    void push_back(const T& val) {
        if (avail == limit)     // get space if needed
            grow();
        unchecked_append(val);  // append the new element
    }
    
private:
    // implementation
    iterator data;    // first element in the Vec
    iterator limit;   // one past the last element in the Vec
    iterator avail;   // now points to (one past) the last available element
    
    // facilities for memory allocation
    std::allocator<T> alloc;     // object to handle memory allocation
    
    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    
    // destroy the elements in teh array and free the memory
    void uncreate();
    
    // support functions for push_back
    void grow();
    void unchecked_append(const T&);
    
};



#endif /* vec_objects_hpp */
