#include <iostream>
#include<vector> 

using namespace std;

void merge(vector<int>& A, vector<int>& B) {
	int a = 0;
	int b = 0;

	vector<int> res;

	for (int i = 0; i < (A.size() + B.size()); i++) {
		if (A[a] < B[b]) {
			res.push_back(A[a]);
			a++;
		}
		else {
			res.push_back(B[b]);
			b++;
		}

		if (a >= A.size() && b >= B.size())
			break;

		if (a >= A.size() && b < B.size()) {
			while (b < B.size()) {
				res.push_back(B[b]);
				b++;
			}
			break;
		}

		if (a < A.size() && b >= B.size()) {
			while (a < A.size()) {
				res.push_back(A[a]);
				a++;
			}
			break;
		}
	}

	A = res;
}


int main()
{	
	vector<int> A{ 1,3,5,7 };
	vector<int> B{ 2,4,6,8,9 };
	merge(A, B);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}