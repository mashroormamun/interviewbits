#include <iostream>
#include<vector> 

using namespace std;

string longestCommonPrefix(vector<string>& A) {
	string a = "";
	char temp;
	bool okay = false;
	for (int i = 0; ; i++) {

		temp = A[0][i];
		okay = true;
		for (int j = 0; j < A.size(); j++) {
			if (A[j].length() > i) {
				if (A[j][i] != temp)
				{
					okay = false;
				}
				else {

				}
			}
			else {
				okay = false;
			}
		}

		if (okay)
			a.append(A[0], i, 1);

		if (!okay)
			return a;
	}

	return a;
}

int main()
{	
	vector<string> A{ "abcdefgh", "aefghijk", "abcefgh" };

	cout << longestCommonPrefix(A) << endl;

	return 0;
}