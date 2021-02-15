#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void transposeMat(vector<vector<int>>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (i != j) {
				swap(vect[i][j], vect[j][i]);
			}
		}
	}
}

void mirrorMat(vector<vector<int>>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j < vect.size() / 2; j++) {
			swap(vect[i][j], vect[i][vect.size() - 1 - j]);
		}
	}
}

void rotate(vector<vector<int> >& A) {
	transposeMat(A);
	mirrorMat(A);
}

int main()
{
	vector<vector<int>> A
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	rotate(A);

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}