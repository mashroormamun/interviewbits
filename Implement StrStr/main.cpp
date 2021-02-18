#include <iostream>

using namespace std;

int strStr(const string A, const string B) {
	//    if(A == NULL || B == NULL)
	//        return -1;
	if (A.length() == 0 || B.length() == 0)
		return -1;

	int lenA = A.length();
	int lenB = B.length();

	int index = 0, result = 0;
	bool ok = false;

	for (int i = 0; i < lenA; i++) {
		if (!ok && A[i] == B[0]) {
			index = i;
			ok = true;
		}

		if (ok) {
			if (A[i] == B[i - index]) {
				if ((i - index + 1) == lenB) {
					return index;
				}
			}

			if (A[i] != B[i - index]) {
				ok = false;
				i--;
			}
		}
	}

	return -1;
}

int main()
{	
	cout << strStr("abcde", "cd") << endl;

	return 0;
}