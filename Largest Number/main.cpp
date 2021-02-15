#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp(int i, int j) {
	string a = to_string(i);
	string b = to_string(j);

	return (a + b) > (b + a);
}

string largestNumber(const vector<int>& AA) {

	vector<int> A(AA.begin(), AA.end());

	sort(A.begin(), A.end(), comp);

	if (A[0] == 0) return "0";

	string res = "";
	for (int i = 0; i < A.size(); i++) {
		res += to_string(A[i]);
	}

	return res;
}

int main()
{
	vector<int>A({ 3, 30, 34, 5, 9 });
	cout << largestNumber(A) << endl;
	return 0;
}