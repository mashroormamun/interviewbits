#include <iostream>

using namespace std;

int lengthOfLastWord(const string A) {
	int flag = -1;

	for (int i = A.length() - 1; i >= 0; i--) {
		if (flag == -1) {
			if (A[i] != ' ') {
				flag = i;
			}
		}
		else {
			if (A[i] == ' ') {
				return (flag - i);
			}
		}
	}

	if (flag == -1)
		return 0;

	return flag + 1;
}

int main()
{	
	cout << lengthOfLastWord("Hello World") << endl;
	
	return 0;
}