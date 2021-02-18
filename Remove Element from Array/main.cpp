#include <iostream>
#include<vector> 

using namespace std;

int removeElement(vector<int>& A, int B) {
	int index = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B) {
			A[index++] = A[i];
		}
	}

	A.resize(index);

	return index;
}


int main()
{	
	vector<int> A{ 1,1,1,2,3,3,4,4,4,4,4,4,5,6,6,6 };
	cout << removeElement(A,4) << endl;

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}