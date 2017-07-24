#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "I am a genius, so I will tell you which of two integers you give me is bigger." << endl;

	cout << "What is the first number? ";
	int first;
	cin >> first;

	cout << "Great.  What is the second? ";
	int second;
	cin >> second;

	cout << "Doing some very difficult calculations..." << endl;

	int bigger = first;

	if (first >= second){
		int bigger = first;
	} else {
		int bigger = second;
	}

	cout << "Tada. The answers is " << bigger << "." << endl;

	return 0;
}