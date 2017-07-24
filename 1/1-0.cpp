#include <iostream>
#include <string>

int main()
{
	// ask for persons name
	std::cout << "Please enter your name: ";

	// declare name as a string
	std::string name;	//define name
	std:: cin >> name;	//read into name

	// write the greeting
	const std::string greeting = "Hello, " + name + "!";

	// build second and fourth lines of output
	const std::string spaces(greeting.size(), ' ');
	const std:: string second = "* " + spaces + " *";

	//build the first and fifth lines of the output
	const std:: string first(second.size(), '*');

	// write it all
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

\/	return 0;
}