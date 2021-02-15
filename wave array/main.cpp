#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(int i, int j) {
	return i < j;
}

vector<int> wave(vector<int>& A) {
	sort(A.begin(), A.end(), comp);

	for (int i = 0; i < A.size() - 1; i += 2) {
		int temp = A[i];
		A[i] = A[i + 1];
		A[i + 1] = temp;
	}

	return A;
}


int main()
{
	vector<int>A({ 3, 30, 34, 5, 9 });
	vector<int>B = wave(A);

	for (int i = 0; i < B.size(); i++)
		cout << B[i] << endl;

	return 0;
}