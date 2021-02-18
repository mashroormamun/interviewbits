#include <iostream>

using namespace std;

bool isVowel(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
	}

	return false;
}

int solve(string A) {
	int sum = 0;

	for (int i = 0; i < A.length(); i++) {
		if (isVowel(A[i])) {
			sum += A.length() - i;
			sum = sum % 1003;
		}
	}

	return sum;
}


int main()
{	
	cout << solve("ABEC") << endl;
	
	return 0;
}