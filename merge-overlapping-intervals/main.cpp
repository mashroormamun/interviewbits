#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

int canBeMerged(Interval A, Interval B) {
	if (A.end >= B.start)
		return B.end;
	return -1;
}

vector<Interval> merge(vector<Interval>& A) {
	vector<Interval> res;
	Interval temp = A[0];

	std::sort(A.begin(), A.end(), compareInterval);

	for (int i = 1; i < A.size(); i++) {
		int endIndex = canBeMerged(temp, A[i]);
		if (endIndex == -1) {
			res.push_back(temp);
			temp = A[i];
		}
		else {
			temp.end = max(temp.end, endIndex);
		}
	}
	res.push_back(temp);

	return res;
}

int main()
{
	vector<Interval>A;
	vector<Interval>res;

	A.push_back(Interval(1, 2));
	A.push_back(Interval(3, 5));
	A.push_back(Interval(6, 7));
	A.push_back(Interval(8, 10));
	A.push_back(Interval(12, 16));
	A.push_back(Interval(4, 9));

	res = merge(A);

	for (int i = 0; i < res.size(); i++)
		cout << res[i].start << " " << res[i].end << endl;

	return 0;
}