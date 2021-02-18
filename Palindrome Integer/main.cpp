#include <iostream>

using namespace std;

int isPalindrome(int A) {
	int number = A;
	int reverse_input = 0;

	while (number > 0) {
		reverse_input = reverse_input * 10 + (number % 10);
		number /= 10;
	}

	if ((A - reverse_input) == 0) true;

	return false;
}

int main()
{	
	cout << isPalindrome(121) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}