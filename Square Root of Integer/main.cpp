#include <iostream>

using namespace std;

int sqrt(int A) {
	if (A == 0 || A == 1)
		return A;
	if (A == 2 || A == 3)
		return 1;

	int start = 1;
	int end = A;
	if (A >= 46341)
		end = 46341;

	int mid = (start + end) / 2;

	while (start <= end) {
		if (mid == (A / mid))
			return mid;

		if (mid < (A / mid)) {
			start = mid + 1;
		}
		else {
			end = end - 1;
		}

		mid = (start + end) / 2;
	}

	return mid;
}


int main()
{	
	cout << sqrt(16) << endl;

	return 0;
}