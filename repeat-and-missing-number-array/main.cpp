#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> repeatedNumber(const vector<int>& A) {
	long long  size = A.size();
	// long long int sumN = 0;
	// long long int n_sum = size*(size+1)/2;

	// long long int sumN2 = 0;
	// long long int n2_sum = size*(size+1)/2*(2*size+1)/3;

	long long  x_y = 0;
	long long  x_plus_y = 0;

	for (long long i = 0; i < size; i++) {
		x_y -= i + 1;
		x_y += A[i];
		x_plus_y -= (i + 1) * (i + 1);
		x_plus_y += (long long)(A[i]) * (long long)(A[i]);
	}


	//    cout << n_sum << " " << sumN << endl;
	//    cout << n2_sum << " " << sumN2 << endl;

		// long long int x_y = n_sum-sumN;
	x_plus_y /= x_y;

	int  x = (int)(x_y + x_plus_y) / 2;
	int  y = x_plus_y - x;

	//    cout << x << " " << y << endl;

	return vector<int>{x, y};
}

int main()
{
	vector<int> B{
		3,1,2,5,3
	};
	
	vector<int>A = repeatedNumber(B);

	for (int i = 0; i < A.size(); i++) {
		//for (int j = 0; j < A[i].size(); j++) {
			cout << A[i] << " ";
		//}
		//cout << endl;
	}

	return 0;
}