#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main() {
	//ask for student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for a nd read teh midterm and final grades
	cout << "Please enter midterm and final grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for hw grades
	cout << "enter all your homework grades, "
			"followed by end-of-file: ";

	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;
	double finalgrade = 0;

	// a variablle into which to read
	double x;

	//invariatn
	while (cin >> x) {
		++count;
		sum += x;
	}

	if (count == 0) {
		finalgrade = 0.2 * midterm + 0.4 * final;
	} else {
		finalgrade = 0.2 * midterm + 0.4* final + 0.4 * sum /count;
	}


	// write the result
	streamsize prec = cout.precision();
	cout << "Final grad is " << setprecision(3)
		<< finalgrade
		<< setprecision(prec) << endl;

	return 0;
}