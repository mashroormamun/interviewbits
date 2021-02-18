#include <iostream>
#include <vector>

using namespace std;

string getValue(string A, int targetIndex, int minIndex, int len) {
	char targetValue = A[targetIndex];
	A[targetIndex] = A[minIndex];
	A[minIndex] = targetValue;

	for (int i = len - 1; i > targetIndex + 1; i--) {
		if (A[i] > A[i - 1]) {
			char temp = A[i];
			A[i - 1] = A[i];
			A[i] = temp;
		}
	}

	for (int i = targetIndex + 1; ; i++) {
		int end = len - 1 - i + targetIndex + 1;
		if (i >= end)
			break;

		char temp = A[i];
		A[i] = A[end];
		A[end] = temp;
	}

	return A;

}

string solve(string A) {
	int len = A.size();
	bool isPossible = false;
	int targetIndex = len - 1;
	int minIndex = len - 1;

	for (int i = len - 1; i > 0; i--) {
		if (A[i] > A[i - 1]) {
			isPossible = true;
			targetIndex = i - 1;
			break;
		}
	}
	if (isPossible) {
		for (int i = len - 1; i > 0; i--) {
			if (A[i] > A[targetIndex]) {
				minIndex = i;
				break;
			}
		}
		return getValue(A, targetIndex, minIndex, len);
	}
	else {
		return "-1";
	}
}

int main()
{	
	cout << solve("218765") << endl;

	return 0;
}