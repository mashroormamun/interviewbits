#include <iostream>

using namespace std;

int fact(int n) {
	int i = 1;
	for (int j = 2; j <= n; j++) {
		i = (i * j) % 1000003;
	}

	return i;
}

int findRank(string A) {
	int rank = 1;
	for (int i = 0; i < A.length() - 1; i++) {
		int diff = 0;
		for (int j = i + 1; j < A.length(); j++) {
			if (A[i] > A[j])
				diff++;

		}

		rank += (diff * fact(A.length() - i - 1)) % 1000003;
	}

	return rank % 1000003;
}

int main()
{	
	cout << findRank("acb") << endl;
	
	return 0;
}