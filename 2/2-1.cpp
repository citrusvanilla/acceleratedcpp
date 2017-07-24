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

	//construct gretting
	const string greeting = "Hello, " + name + "!";

	//vars for output
	const int tb_border = 1;
	const int lr_border = 3;
	const int rows = tb_border * 2 + 3;
	const string::size_type cols = greeting.size() + lr_border * 2 + 2;

	//outer loop for rows
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		// invariant: we have written c characters so far in the current row
		while (c != cols) {
			//is it time to write the greeting?
			if (r == 1 + tb_border && c == lr_border + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				// are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols-1){
					cout << "*";
				} else {
					cout << " ";
				}
				++c;
			}
		}
		cout << endl;
	}

	return 0;
}