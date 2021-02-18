#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

void sortColors(vector<int>& A) {
	sort(A.begin(), A.end());
}

int main()
{	
	vector<int> A{ 0, 1, 2, 0, 1, 2 };
	sortColors(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}