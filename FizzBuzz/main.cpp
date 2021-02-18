#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzBuzz(int A) {
	vector<string> sol;

	for (int i = 1; i <= A; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			sol.push_back("FizzBuzz");
		}
		else if (i % 3 == 0) {
			sol.push_back("Fizz");
		}
		else if (i % 5 == 0) {
			sol.push_back("Buzz");
		}
		else {
			sol.push_back(to_string(i));
		}
	}
	return sol;
}


int main()
{	
	vector<string> A = fizzBuzz(5);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}