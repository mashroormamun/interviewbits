#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(const vector<int>& A) {
	int max_sum = 0;
	int sum = 0;

	if (A.size() != 0) {
		max_sum = sum = A[0];
	}

	for (int i = 1; i < A.size(); i++) {
		sum += A[i];
		if (max_sum < 0 && max_sum < A[i]) max_sum = A[i];
		if (sum > max_sum) max_sum = sum;
		if (sum < 0) sum = 0;
	}

	return max_sum;
}


int main()
{
	vector<int>A({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });

	cout << maxSubArray(A) << endl;

	return 0;
}