#include <iostream>

using namespace std;

int divide(int AA, int BB) {
	if (BB == 1)return AA;
	if (AA == INT_MIN && BB == -1)
		return INT_MAX;

	int sign = ((AA < 0) ^ (BB < 0)) ? -1 : 1;

	// Update both divisor and 
	// dividend positive 
	long long int A = AA;

	long long int B = abs(BB);
	if (A < 0) B = -B;

	// Initialize the quotient 
	long long int quotient = 0;
	if (A < 0) {
		while (B >= A) {
			A -= B;
			++quotient;
		}
	}
	else {
		while (A >= B) {
			A -= B;
			++quotient;
		}
	}
	if ((sign * quotient) >= INT_MAX) quotient = INT_MAX;
	if ((sign * quotient) < INT_MIN) quotient = INT_MAX;


	return sign * quotient;
}

int main()
{	
	cout << divide(5,2) << endl;
	
	return 0;
}