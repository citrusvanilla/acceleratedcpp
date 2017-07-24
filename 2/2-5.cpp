#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(){
	// prompt for shape
	cout << "What shape? ";
	string shape;
	cin >> shape;

	int size;
	int w_size;
	int h_size;

	if (shape == "square" || shape == "triangle"){
		cout << "What size? ";
		cin >> size;
	} else {
		// prompt for width
		cout << "What size width? ";
		cin >> w_size;

		// prompt for height
		cout << "What size height? ";
		cin >> h_size;
	}

	if (shape == "triangle"){
		for (int r = 0; r != size; ++r){
			string output(1+r, '*');
			cout << output << endl;
		}

	}

	if (shape == "square") {
		for (int r= 0; r != size; ++r) {
			string output(size, '*');
			cout << output << endl;
		}
	}

	if (shape == "rectangle") {
		for (int r=0; r != h_size; ++r){
			string output(w_size, '*');
			cout << output << endl;
		}
	}

	return 0;
}