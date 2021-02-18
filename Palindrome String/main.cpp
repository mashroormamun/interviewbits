#include <iostream>
#include<vector> 
#include <algorithm>

using namespace std;

char uniform(char c) {
	if (c >= 'a' && c <= 'z')
	{
		return c - ('a' - 'A');
	}
	return c;
}

int isPalindrome(string A) {
	A.erase(std::remove(A.begin(), A.end(), ' '), A.end());
	A.erase(std::remove(A.begin(), A.end(), ','), A.end());
	A.erase(std::remove(A.begin(), A.end(), ':'), A.end());
	A.erase(std::remove(A.begin(), A.end(), '"'), A.end());

	for (int i = 0; i < A.length() / 2; i++) {
		if (uniform(A[i]) != uniform(A[A.length() - 1 - i]))
			return 0;
	}
	return 1;
}


int main()
{	
	cout << isPalindrome("abcddcba") << endl;
	
	return 0;
}