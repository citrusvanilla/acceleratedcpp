#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;



int main(){
	// ask for student's names and grades
	
	vector<string> names;
	vector<double> grades;

	bool done = false;

	while (!done) {
		cout << "student's name: ";
		string name;
		cin >> name;
		names.push_back(name);

		cout << "midterm grade: ";
		double mt_grade;
		cin >> mt_grade;

		cout << "final grade: ";
		double f_grade;
		cin >> f_grade;

		double c_grade = 0.4 * mt_grade + 0.6 * f_grade;
		grades.push_back(c_grade);

		cout << "More? Y/N: ";
		string Y_N;
		cin >> Y_N;

		if (Y_N == "N") {
			done = true;
		}

	}

	typedef vector<string>::size_type vec_sz;
	vec_sz size = names.size();

	for (vec_sz i = 0; i != size; ++i) {
		cout << names[i] << "\'s class grade is: " << grades[i] << endl;
	}

	return 0;
}