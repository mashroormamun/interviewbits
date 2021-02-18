#include <iostream>
#include<vector> 

using namespace std;

vector<int> intersect(const vector<int>& A, const vector<int>& B) {
	vector<int> res;
	int a = 0, b = 0;

	while (a < A.size() && b < B.size()) {
		if (A[a] == B[b])
		{
			res.push_back(A[a]);
			a++;
			b++;
		}
		else {
			if (A[a] < B[b])
				a++;
			else b++;
		}
	}

	return res;
}

int main()
{	
	vector<int> C{ 1,2,3,3,4,5,6 };
	vector<int> B{ 3,3,5 };
	vector<int> A = intersect(C, B);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}