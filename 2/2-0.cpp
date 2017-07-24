#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	cout << "What is your name?" << endl;
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";

	// the number of blanks surrounding the greeting
	const int pad = 1;

	// total number of rows to write
	const int rows = pad * 2 + 3;

	// length of our rows, represented as columns
	// type std::string::size_type holds string lengths
	// it is an unsigned type that can hold values greater than the int type
	const string::size_type cols = greeting.size() + 2 * pad + 2;


	// separate the output from the input with a blank line
	cout << endl;

	// write rows rowsof output
	// invariant: we have written r rows of output so far

	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		// invariant: we have written c characters so far in the current row
		while (c != cols) {
			// write one or more characters here
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
				cout << "*";
				++c;
			} else {
				// write one of more nonborder characters
				if (r == pad + 1 && c == pad + 1){
					cout << greeting;
					c += greeting.size();
				} else {
					cout << " ";
					++c;
				}
				// adjust the value of c to maintain the invariant
			}
			// adjust the value of c to maintain the invariant
		}
		cout << endl;

	}

	// at the end of the while loop, the invariant is TRUE

	return 0;
}