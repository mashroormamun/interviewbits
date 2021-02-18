#include <iostream>
#include <vector>

using namespace std;

int hammingDistance(const vector<int>& A) {
	long long int ans = 0;

	for (int i = 0; i < 30; i++) {
		int count = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] & (1 << i)) {
				++count;
			}
		}
		ans += count * (A.size() - count) * 2;
	}

	return (int)((ans) % 1000000007);
}

int main()
{	
	vector<int> A{ 2,4,6 };
	cout << hammingDistance(A) << endl;

	return 0;
}