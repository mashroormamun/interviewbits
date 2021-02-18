#include <iostream>
#include <vector>

using namespace std;

char getChar(int A) {
	if (A == 0) return 'Z';
	return (char)(A - 1 + 'A');
}

string convertToTitle(int A) {
	string res = "";
	while (A != 0) {
		int d = A % 26;
		res += getChar(d);
		if (d == 0) A--;

		A /= 26;
	}

	std::reverse(res.begin(), res.end());

	return res;
}

int main()
{	
	cout << convertToTitle(28) << endl;
	/*vector<int> A{1,0};

	arrange(A);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}*/

	return 0;
}