#include <iostream>
#include<vector> 

using namespace std;

int binarySearch(vector<vector<int> >& arr, int p, int r, int num, int row) {
	if (p <= r) {
		int mid = (p + r) / 2;
		if (arr[mid / row][mid % row] == num)
			return 1;
		else if (arr[mid / row][mid % row] > num)
			return binarySearch(arr, p, mid - 1, num, row);
		else
			return binarySearch(arr, mid + 1, r, num, row);
	}
	return 0;
}

int searchMatrix(vector<vector<int> >& A, int B) {
	int row = A.size();
	if (row == 0) return 0;
	int col = A[0].size();

	return binarySearch(A, 0, row * col - 1, B, col);
}


int main()
{	
	vector<vector<int> > A{
		{ 1,   3,  5,  7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	cout << searchMatrix(A, 16) << endl;
	
	return 0;
}