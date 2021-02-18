#include <iostream>
using namespace std;

unsigned int reverse(unsigned int A) {
	unsigned int result = 0;

	for (int i = 0; i < 32; i++) {
		result = (result << 1) | ((A >> i) & 0x01);
	}

	return result;
}

int main()
{	
	cout << reverse(3) << endl;
	
	return 0;
}