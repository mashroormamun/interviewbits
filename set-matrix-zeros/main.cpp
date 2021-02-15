#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void setZeroes(vector<vector<int> >& A) {
	set<int> row_zero;
	set<int> column_zero;

	int row = A.size();
	int column = A[0].size();

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (A[i][j] == 0) {
				row_zero.insert(i);
				column_zero.insert(j);
			}
		}
	}

	for (auto itr = row_zero.begin(); itr != row_zero.end(); ++itr)
	{
		for (int i = 0; i < column; i++) {
			A[*itr][i] = 0;
		}
	}

	for (auto itr = column_zero.begin(); itr != column_zero.end(); ++itr)
	{
		for (int i = 0; i < row; i++) {
			A[i][*itr] = 0;
		}
	}

}

int main()
{
	vector <vector<int>> A{
		{1,0,1},
		{1,1,1},
		{1,1,1},
	};
	
	setZeroes(A);

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}