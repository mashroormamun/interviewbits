#include <iostream>

using namespace std;

int reverse(int A) {
	bool isNeg = A < 0 ? 1 : 0;

	A = isNeg ? -A : A;

	long long int revNum = 0;

	while (A > 0) {
		revNum = 10 * revNum + A % 10;
		A /= 10;
	}

	if (revNum > (pow(2, 31) - 1))
		return 0;

	revNum = isNeg ? -revNum : revNum;

	return revNum;
}

int main()
{	
	cout << reverse(1234) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}