#include <iostream>

using namespace std;

int numSetBits(unsigned int A) {
	int count = 0;

	for (int i = 0; i < 32; i++) {
		if (((A >> i) & 0x01) == 1) {
			count++;
		}
	}

	return count;
}

int main()
{	
	cout << numSetBits(11) << endl;
	
	return 0;
}