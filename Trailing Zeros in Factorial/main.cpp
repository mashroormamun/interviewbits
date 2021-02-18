#include <iostream>

using namespace std;

int trailingZeroes(int A) {
	int count = 0;

	for (int i = 5; (A / i) > 0; i *= 5) {
		count += A / i;
	}

	return count;
}

int main()
{	
	cout << trailingZeroes(200) << endl;

	return 0;
}