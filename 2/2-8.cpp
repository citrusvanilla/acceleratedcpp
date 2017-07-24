#include <iostream>

using std::cout;
using std::endl;

int main(){
	int i = 1;
	int product = 1;
	
	// product of numbers in the half range [1,10)
	// i.e. 1*2*3*4*5*6*7*8*9
	while (i < 9) {
		product *= i + 1;
		i += 1;
	}
	cout << product << endl;

	return 0;
}