#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> primesum(int A) {
	vector<bool> mat(A + 1);
	vector<int> pp;

	mat[0] = 1;
	mat[1] = 1;
	mat[2] = 0;

	int sq = sqrt(A);
	vector<int> res;
	res.push_back(2);

	for (int i = 4; i <= A; i += 2) {
		mat[i] = 1;
	}

	for (int i = 3; i <= A; i += 2) {
		int j = i;

		if (mat[i] == 0) {
			res.push_back(i);
			j += i;
		}

		for (; j <= A; j += i) {
			mat[j] = 1;
		}
	}

	for (int i = 0; i < res.size(); i++) {
		int index = A - res[i];
		if (index < 0) continue;

		if (res[i] > index)
			break;

		if (mat[index] == 0) {
			pp.push_back(res[i]);
			pp.push_back(index);
			return pp;
		}
	}

	return pp;
}

int main()
{	
	vector<int>A = primesum(40);

	for (int i = 0; i < A.size(); i++) {
		//for (int j = 0; j < A[i].size(); j++) {
			cout << A[i] << " ";
		//}
		//cout << endl;
	}

	return 0;
}