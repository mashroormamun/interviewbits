#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& B) {
	int index = 0;
	for (int i = 0; i < B.size(); i++) {
		if (B[i] != 0) {
			index = i;
			break;
		}
	}

	vector<int> A(B.begin() + index, B.end());

	int lastIndex = A.size() - 1;
	A[lastIndex] += 1;

	int extra = A[lastIndex] / 10;
	A[lastIndex] %= 10;

	if (extra != 0)
		for (int i = A.size() - 2; i >= 0; --i) {
			A[i] += extra;
			extra = A[i] / 10;
			A[i] %= 10;
			if (extra == 0)
				break;
		}

	if (extra != 0) {
		A.resize(A.size() + 1);
		A[0] = 1;
	}

	return A;
}



int main()
{
	vector<int>A({ 1, 2, 3 });
	plusOne(A);
	return 0;
}