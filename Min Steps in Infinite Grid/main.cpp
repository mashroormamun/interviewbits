#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coverPoints(vector<int>& A, vector<int>& B) {
	int min_dist = 0;

	for (int i = 1; i < A.size(); i++) {
		min_dist += std::max(std::abs(A[i - 1] - A[i]), std::abs(B[i - 1] - B[i]));
	}

	return min_dist;
}


int main()
{
	vector<int>A({ 0, 1, 1 });
	vector<int>B({ 0, 1, 2 });

	cout << coverPoints(A, B) << endl;

	return 0;
}