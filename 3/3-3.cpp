#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::vector;
using std::string;

int main(){
	
	typedef vector<string>::size_type vec_sz;

	// ask user for list of words on input
	

	cout << "Please enter a list of words, " <<
			"followed by end-of-file: ";
	
	vector<string> words;
	string x;

	vector<int> counts;


	// invariant: words contains all the words read so far
	while (cin >> x) {
		bool found = false;

		for (vec_sz i = 0; i < words.size(); ++i) {
			if (x == words[i]) {
				++counts[i];
				found = true;
			}
		}


		if (!found) {
			words.push_back(x);
			counts.push_back(1);
		}
			
		
	}


	// print output
  	for (vec_sz i = 0; i < words.size(); ++i)
    	cout << words[i] << " appeared " << counts[i] << " times" << endl;

  	return 0;
}