#include <iostream>

using namespace std;

int gcd(int A, int B) {
	int temp;

	if (A == 0)
		return B;

	if (B == 0)
		return A;

	if (A < B) {
		A = A ^ B;
		B = A ^ B;
		A = A ^ B;
	}

	while (A > 0) {
		temp = A % B;
		if (temp == 1) {
			return 1;
		}
		else if (temp == 0) {
			return B;
		}

		A = B;
		B = temp;
	}

	return 1;
}


int main()
{	
	cout << gcd(12,16) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}