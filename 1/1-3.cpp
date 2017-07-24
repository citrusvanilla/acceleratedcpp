#include <iostream>
#include <string>

int main()
{
	// declare variable s string to be constant and write to
	// standard output

	{
		const std::string s = "a string";
		std::cout << s << std::endl;
	}
	
	// (re)declare the same variable s as a string to take
	// a different string literal

	// this works because the first declaration occurs in a
	// separate block from the other- that is to say the scope
	// of s enclosed in block one is separate from block 2.
	// remember that the local variable in scope one is "destroyed"
	// when the block is exited.
	{
		const std::string s = "another string";
		std::cout << s << std::endl;
	}
	return 0;
}