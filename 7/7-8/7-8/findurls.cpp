//
//  findurls.cpp
//  7-8
//
//  Created by justin fung on 7/26/17.
//  Copyright © 2017 justin fung. All rights reserved.
//

#include "findurls.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;


// 6.1.3.(107) finding urls
// predicate that evaluates if a character can be in a url or not
bool not_url_char(char c)
{
    // characters, in addition to alphanumerics, that can appear in a URL
    // NOTE: 'static' denotes a 'storage class specifier', which are preserved
    // across invocations of the function.  the object is initilaized the first
    // time it is called, and subsequent calls will use the same object.
    static const string url_ch = "~;/?:@=&$-_.+'(),";
    
    // see whether c can appear in a URL and return the negative.
    // NOTE: this function tests whether its argument is alphanumeric or not
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}


// 6.1.3.(107) finding urls
// function for finding the end of a url
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

// 6.1.3.(108)
// function for finding the beginning of a URL
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    
    typedef string::const_iterator iter;
    
    // i marks where the separator was found
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        
        // make sure the separator isn't as the beginning or end of the line
        if (i != b && i + sep.size() != e) {
            
            // beg marks the beginning of the prtocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            
            // is there at least one appropriate characer before and after the separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        
        // the separator we found wasn't part of a URL; advance i past this separator
        i += sep.size();
    }
    return e;
}


// 6.1.3.(106) finding urls
// function for finding urls
vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    // look through the entire input
    while (b != e) {
        
        // look for one or more letters followed by ://
        b = url_beg(b, e);
        
        // if we found it
        if (b != e) {
            
            //get the rest of the URL
            iter after = url_end(b, e);
            
            // remember the URL
            ret.push_back(string(b, after));
            
            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}
