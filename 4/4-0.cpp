// include direcives and using-declarations for library facilities
// code for the median function
// code for  the first grade function
// code for the second grade function
// code for read_hw function

int main() {
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all your homework grades, "
			"followed by the end of file: ";

	vector<double> homework;

	// read the homework grades
	read_hw(cin, homework);

	// compute and generate the final grade, if possible
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
				<< final_grade << setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "You must enter your grades. "
						"Please try again." << endl;
		return 1;
	}

	return 0;
}