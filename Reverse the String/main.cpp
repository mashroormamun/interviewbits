#include <iostream>

using namespace std;

void revv(string& str, int start, int end) {
	char ch;
	int j = 0;
	for (int i = start; i < end - ((end - start) / 2); i++) {
		ch = str[i];
		str[i] = str[end - j];
		str[end - j++] = ch;
	}
}

string solve(string A) {
	if (A.length() == 1 || A.length() == 0) return A;

	int start = -1, end = -1;

	for (int i = 0; i < A.length(); i++) {
		if (start == -1) {
			if (A[i] != ' ') {
				start = i;
			}
		} if (start != -1) {
			if (A[i] != ' ') {
				end = i;
			}
		}

		if (start != -1 && end != -1 && (A[i] == ' ' || i == A.length() - 1)) {
			//cout << start << " " << end << endl;
			revv(A, start, end);
			start = -1;
			end = -1;
		}
	}

	revv(A, 0, A.length() - 1);

	return A;
}

int main()
{	
	cout << solve("abcd efgh ijkl") << endl;
	
	return 0;
}