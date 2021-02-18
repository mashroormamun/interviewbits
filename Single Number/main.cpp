#include <iostream>
#include<vector> 

using namespace std;

int singleNumber(const vector<int>& A) {
	int number = 0;

	for (int i = 0; i < A.size(); i++) {
		number ^= A[i];
	}

	return number;
}

int main()
{	
	vector<int> A{ 1,2,1,2,3 };
	cout << singleNumber(A) << endl;
	
	return 0;
}