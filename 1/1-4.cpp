#include <iostream>
#include <string>

int main()
{  //scope main here


	{ //scope main-1 here
		const std::string s = "a string";
	 	std::cout << s << std::endl;

		{ //scope main-1-1 here
			const std::string s = "another string";
			std::cout << s << std::endl; 
		}

		
	}
	return 0;
}