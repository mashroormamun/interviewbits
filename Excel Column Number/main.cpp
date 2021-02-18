#include <iostream>
#include <vector>

using namespace std;

int getValue(char c) {
	c = c >= 'a' ? c - ('a' - 'A') : c;
	c = c - 'A' + 1;
	return (int)c;
}

int titleToNumber(string A) {
	int sum = 0;
	for (int i = 0; i < A.length(); i++) {
		sum += pow(26, A.length() - i - 1) * getValue(A[i]);
	}

	return sum;
}


int main()
{	
	cout << titleToNumber("AB") << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}