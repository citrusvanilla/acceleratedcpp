#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::sort;
using std::streamsize;
using std::setprecision;




int main(){
	// prompt user for integers
	cout << "Please enter a set of integers "
			"follow by the end-of-file." << endl;

	// initialize vector
	vector<double> integers;
	double x;

	// invariant: integers contains all the integers entered so far
	while (cin >> x)
		integers.push_back(x);

	// get size of vector
	typedef vector<double>::size_type vec_sz;
	vec_sz size = integers.size();


	// check that integers were actually entered	
	if (size == 0) {
		cout << endl << "you must enter your grades. "
						"Please try again." << endl;
		return 1;
	}

	// sort the grades
	sort(integers.begin(), integers.end());

	// get quartile indicies
	vec_sz mid = integers.size() / 2; // is an integer!
	vec_sz lower_half_end;
	vec_sz upper_half_begin;

	// compute quartiles
	if (integers.size() % 2 != 0) {
		lower_half_end = mid; // upper half plane exclude
		upper_half_begin = mid + 1; // lower half plane include
	} else {
		lower_half_end = mid;
		upper_half_begin = mid;
	}

	cout << "Q1" << endl;
	cout << median(integers , 0, lower_half_end) << endl;

	cout << "Q2" << endl;
	cout << median(integers, 0, integers.size()) << endl;

	cout << "Q3" << endl;
	cout << median(integers, upper_half_begin, integers.size()) << endl;

	cout << "Q4" << endl;
	cout << integers[integers.size()-1] << endl;

	return 0;

	return 0;

}