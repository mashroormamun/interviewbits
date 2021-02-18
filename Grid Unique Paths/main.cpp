#include <iostream>

using namespace std;

int uniquePaths(int A, int B) {
	if (A == 1 || B == 1) {
		return 1;
	}

	return uniquePaths(A - 1, B) + uniquePaths(A, B - 1);
}


int main()
{	
	cout << uniquePaths(2,2) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}