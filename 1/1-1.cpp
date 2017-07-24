#include <iostream>
#include <string>

int main()
{
	// initialize the variable hello with the string literal "hello"
	// and declare its type to be std::string.  we also want it
	// to be constant
	const std::string hello = "Hello";
	
	/* initialize the variable message of type std::string to be
	a concatenation of the variable hello and the string literals
	", world" and "!" .
	since the + operator is left associative, the concatentation
	of a string literal with a string literal does not occur */
	const std::string message = hello + ", world" + "!";

	std::cout << message << std::endl;
	return 0;
}