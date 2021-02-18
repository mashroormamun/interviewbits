#include <iostream>

using namespace std;

int solve(int A, int B, int C, int D) {
	if ((A == B) && (C == D))
		return 1;

	if (A == C)
		if (B == D)
			return 1;

	if (A == D)
		if (B == C)
			return 1;

	return 0;
}


int main()
{	
	cout << solve(1,1,2,2) << endl;
	
	return 0;
}