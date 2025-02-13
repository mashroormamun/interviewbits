#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

bool isOverlapping(vector<int> &a, vector<int> &b) {
    return a[1] >= b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) return intervals;

    sort(intervals.begin(), intervals.end(), comp);

    vector<int> intermediate = intervals[0];

    vector<vector<int>> result;


    for(int i=1;i<intervals.size();i++) {
        if(isOverlapping(intermediate, intervals[i])) {
            intermediate[0] = min(intermediate[0], intervals[i][0]);
            intermediate[1] = max(intermediate[1], intervals[i][1]);

        } else {
            result.push_back(intermediate);
            intermediate = intervals[i];

        }
    }

    result.push_back(intermediate);

    return result;
}

int main()
{
    vector<vector<int>> intervals;
    intervals.push_back(vector<int>{1,3});
    intervals.push_back(vector<int>{3,6});
    intervals.push_back(vector<int>{8,10});
    intervals.push_back(vector<int>{15,18});
    intervals.push_back(vector<int>{100,100});

    auto result = merge(intervals);

    for(int i=0;i<result.size();i++) {
        cout << result[i][0] << "-" << result[i][1] << endl;
    }

    return 0;
}