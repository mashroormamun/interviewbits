#include <iostream>
#include <vector>

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

/*
vector<int> getMultipliers(int A) {

	vector<int> muls;

	while (A != 1) {
		//        cout << A << endl;
		int i = 2;
		while (i <= A) {
			if ((A % i) == 0) {
				muls.push_back(i);
				A /= i;
				break;
			}
			i++;
		}
	}

	return muls;
}
*/

int cpFact(int A, int B) {
	return A / gcd(A, B);
}

int main()
{	
	cout << cpFact(30,12) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}