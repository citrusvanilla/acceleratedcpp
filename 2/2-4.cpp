#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	//prompt for name and read it in
	cout << "What is your name?" << endl;
	string name;
	cin >> name;

	cout << "How much spacing?" << endl;
	int border;
	cin >> border;

	//construct gretting
	const string greeting = "Hello, " + name + "!";

	//vars for output
	const int rows = border * 2 + 3;
	const string::size_type cols = greeting.size() + border * 2 + 2;
	const string spaces(border, ' ');
	const string spaces2((greeting.size() + 2*border), ' ');

	//outer loop for rows
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		// invariant: we have written c characters so far in the current row
		while (c != cols) {
			//is it time to write the greeting?
			if (r == 1 + border && c == border + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				// are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols-1){
					cout << "*";
				} else {
					// are we on the greeting line?
					if (r == 1 + border){
						cout << spaces;
						c += spaces.size();
					}
					else {
						// are we on a line that is not the greeting, first or last?
						cout << spaces2;
						c += greeting.size() + 2 * border;
					}
				}
				++c;
			}
		}
		cout << endl;
	}

	return 0;
}