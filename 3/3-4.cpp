#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::string;

int main(){
	cout << "Write a bunch of strings here, "
			"followed by EOF:" << endl;
	vector<string> strings;
	string x;

	//invariant: strings contains a vector of string strings read so far
	while (cin >> x)
		strings.push_back(x);

	//check that strings were entered
	typedef vector<string>::size_type vec_sz;
	vec_sz size = strings.size();
	if (size == 0) {
		cout << endl << "You must enter some strings. "
						"Please try again." << endl;
		return 1;
	}

	// calculate longest and shortest strings in the vector
	string shortest = strings[0];
	string longest = strings[0];

	for (vec_sz i = 0; i != size; ++i) {
		if (strings[i].size() < shortest.size()) {
			shortest = strings[i];
		}
		if (strings[i].size() > longest.size()) {
			longest = strings[i];
		}
	}

	//print out results
	cout << "LONGEST: " << longest << endl;
	cout << "SHORTEST: " << shortest << endl;

	return 0;

}