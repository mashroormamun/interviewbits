#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isPower(int A) {
	if (A == 1) return 1;

	if (A == 2) return 0;

	if ((A & (A - 1)) == 0) {
		return 1;
	}

	for (int x = 3; x <= sqrt(A); x++) {

		int y = 2;

		long long int p = pow(x, y);
		while (p <= A) {
			if (p == A) return 1;

			y++;
			p = pow(x, y);
		}
	}

	return 0;
}



int main()
{	
	cout << isPower(16) << endl;
	/*vector<string> A = fizzBuzz(5);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}
	*/

	return 0;
}