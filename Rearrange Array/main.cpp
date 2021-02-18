#include <iostream>
#include <vector>

using namespace std;

void arrange(vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		A[i] += (A[A[i]] % A.size()) * A.size();
	}

	for (int i = 0; i < A.size(); i++) {
		A[i] /= A.size();
	}
}

int main()
{	
	vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	return 0;
}