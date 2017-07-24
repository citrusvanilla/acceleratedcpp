#include <iostream>
#include <string>

int main()
{
	// initialize a string variable names exclam to have string literal
	// value of "!"
	const std::string exclam = "!";

	// initialize a string variable message to be the concatenation of
	// string literal "Hello" and string literal ", world!" and
	// variable exclam
	const std::string message = "Hello" + ", world" + exclam;

	//write to IO stream
	std::cout << message << std::endl;
	return 0;
}