// a small C++ program
// input-output is part of the "standard library", not the core language
// iostream is for sequential io, not random access io
// angle bracket enclosure is for standard header
#include <iostream>


// every c++ program must have a main() function
// int is the name in the core language for integer
// returns 0 for success, not zero for failure
int main()
{
	// std is the namespace for the standard library, included above
	// this line tells the standard library to write the string to the cout, followed by endline
	// << is a stanard library operator
	// ending a line with a semicolon discards the resulting value
	// in this case, the side effect is the writing of the string to the iostream
	// scope here is std, from the standard library namespace
	// cout is definied in the std namesapce
	std::cout << "Hello, world!" << std::endl;
 	
	// the definition of the main function requires every return statement to be an integer
 	return 0;
}