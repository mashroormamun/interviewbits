#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solve(int A) {
	vector<vector<int>> res;

	for (int i = 0; i <= A; i++) {
		vector<int> r;

		if (i == 0) {
			r.push_back(1);
		}
		else {
			vector<int> prev_row = res[i - 1];
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i) r.push_back(1);
				else {
					r.push_back(prev_row[j] + prev_row[j - 1]);
				}

			}
		}

		if (i == A)
			return r;

		res.push_back(r);
	}
}

int main()
{
	/*
	vector <vector<int>> B{
		{1,0,1},
		{1,1,1},
		{1,1,1},
	};*/
	
	vector<int>A = solve(4);

	for (int i = 0; i < A.size(); i++) {
		//for (int j = 0; j < A[i].size(); j++) {
			cout << A[i] << " ";
		//}
		//cout << endl;
	}

	return 0;
}