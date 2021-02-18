#include <iostream>
#include<vector> 

using namespace std;

int removeDuplicates(vector<int>& A) {
	int vSize = A.size();

	if (vSize < 2) {
		return vSize;
	}

	int count = 1;

	for (int i = 1; i < vSize; i++) {
		if (A[i] != A[i - 1]) {
			A[count++] = A[i];
		}
	}

	A.resize(count);

	return count;
}


int main()
{	
	vector<int> A{ 1,2,3,3,4,5,6 };
	cout << removeDuplicates(A) << endl; 

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}