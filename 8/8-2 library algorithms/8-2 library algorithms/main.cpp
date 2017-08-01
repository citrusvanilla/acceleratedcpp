//
//  main.cpp
//  8-2 library algorithms
//
//  Created by justin fung on 7/31/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::domain_error;
using std::string;


// equal(b, e, b2)
// iterators are sequetial read itertors, and use the following operations:
// equality(==), dereference(*), increment(++)
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 b, InputIterator1 e, InputIterator2 b2)
{
    while (b != e) {
        if (*b != b2)
            return false;
        ++b; ++b2;
    }
    return true;
}

// find(b, e, t)
// iterator is sequential read iterator
template <class InputIterator, class Value>
InputIterator find(InputIterator begin, InputIterator end, Value val)
{
    while (begin != end) {
        if (*begin == val) {
            return begin;
            ++begin;
            }
    }
    return end;
}

// copy(b, e, d)
// sequential write-only access
template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator begin1, InputIterator end1, OutputIterator begin2)
{
    while (begin1 != end1) {
        *begin2 = *begin1;
        ++begin1;
        ++begin2;
    }
    
    return begin2;
}

// remove_copy_if(b, e, d, p)
// Copies the elements in the range [first,last) to the range beginning at result,
// except those elements for which pred returns true.
template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator remove_copy_if(InputIterator begin1, InputIterator end1, OutputIterator begin2, Predicate pred)
{
    while (begin1 != begin2) {
        if (pred(*begin1) == false) {
            *begin2 = *begin1;
            ++begin2;
        }
        ++begin1;
    }
    return begin2;
}

// transform(b, e, d, f)
// "Applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result."
// returns An iterator pointing to the element that follows the last element written in the result sequence.
template <class InputOperator, class OutputOperator, class Operation>
OutputOperator transform(InputOperator begin1, InputOperator end1, OutputOperator begin2, Operation op)
{
    while (begin1 != end1) {
        *begin2 = op(*begin1);
        ++begin1;
        ++begin2;
    }
    return begin2;
}

// accumulate(b, e, t)
// Returns the result of accumulating all the values in the range [first,last) to init.
// The default operation is to add the elements up, but a different operation can be specified as binary_op.
template <class InputOperator, class Init>
Init accumulate(InputOperator begin, InputOperator end, Init val)
{
    while (begin != end) {
        val += *begin;
        ++begin;
    }
    return val;
}

// search(b, e, b2, e2)
// Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.
// An iterator to the first element of the first occurrence of [first2,last2) in [first1,last1). If the sequence is not found, the function returns last1.
template <class InputOperator1, class InputOperator2>
InputOperator1 search(InputOperator1 begin1, InputOperator1 end1, InputOperator2 begin2, InputOperator2 end2)
{
    while (begin1 != end1) {
        
        if (*begin2 == *begin1) {
            InputOperator1 begin3 = begin1;
            while (*begin3 == *begin2 && begin2 != end2) {
                ++begin3; ++begin2;
            }
            if (begin2 == end2) {
                return begin1;
            } else {
                continue;
            }
        }
        ++begin1;
    }
    return end1;
}

// find_if(b, e, p)
// Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.
template <class InputOperator, class Predicate>
InputOperator find_if(InputOperator begin, InputOperator end, Predicate pred)
{
    while (begin != end) {
        if (pred(*begin))
            return begin;
        ++begin;
    }
    return end;
}

// remove_copy(b, e, d, t)
// Copies the elements in the range [first,last) to the range beginning at result, except those elements that compare equal to val.
// returns An iterator pointing to the end of the copied range, which includes all the elements in [first,last) except those that compare equal to val.
template <class InputOperator, class OutputOperator, class Val>
OutputOperator remove_copy(InputOperator begin1, InputOperator end1, OutputOperator begin2, Val val)
{
    while (begin1 != end1) {
        if (*begin1 != val) {
            **begin2 = *begin1;
        }
        ++begin1;
        ++begin2;
    }
    return begin2;
}

// remove(b, e, t)
// Transforms the range [first,last) into a range with all the elements that compare equal to val removed, and returns an iterator to the new end of that range.
template <class InputOperator, class Val>
InputOperator remove(InputOperator begin, InputOperator end, Val val)
{
    InputOperator result = begin;
    while (begin != end) {
        if (*begin != val) {
            *result = *begin;
            ++result;
        }
        ++begin;
    }
    return result;
}

// partition(b, e, p)
// Rearranges the elements from the range [first,last), in such a way that all the elements for which pred returns true precede all those for which it returns false. The iterator returned points to the first element of the second group


template <class Iterator, class Predicate>
Iterator partition (Iterator first, Iterator last, Predicate pred)
{
    while (first!=last) {
        while (pred(*first)) {
            ++first;
            if (first==last) return first;
        }
        do {
            --last;
            if (first==last) return first;
        } while (!pred(*last));
        swap (*first,*last);
        ++first;
    }
    return first;
}
