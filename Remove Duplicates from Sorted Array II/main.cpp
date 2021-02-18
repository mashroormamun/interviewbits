#include <iostream>
#include<vector> 

using namespace std;

int removeDuplicates(vector<int>& A) {
	int vSize = A.size();
	int cc = 1;

	if (vSize < 2) {
		return vSize;
	}

	int count = 1;

	for (int i = 1; i < vSize; i++) {
		if (A[i] != A[i - 1]) {
			A[count++] = A[i];
			cc++;
		}
		else if (cc >= 1) {
			A[count++] = A[i];
			cc = 0;
		}
	}

	A.resize(count);

	return count;
}

int main()
{	
	vector<int> A{ 1,1,1,2,3,3,4,4,4,4,4,4,5,6,6,6 };
	cout << removeDuplicates(A) << endl; 

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}