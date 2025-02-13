#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for(int i=0;i<intervals.size();i++) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if(intervals[i][0] <= newInterval[1]) {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            } else if(newInterval[1] < intervals[i][0]) {
                result.push_back(vector<int>{newInterval[0], newInterval[1]});
                newInterval[0] = -1;
                newInterval[1] = -1;
                result.push_back(intervals[i]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        if(newInterval[0]!=-1) {
            result.push_back(vector<int>{newInterval[0], newInterval[1]});
        }

        return result;
    }
};

int main() {
    vector<vector<int>> intervals;
    intervals.push_back(vector<int>{1,3});
    intervals.push_back(vector<int>{4,6});
    intervals.push_back(vector<int>{9,9});
    
    vector<int> newInterval{2,5};

    Solution s;

    auto v = s.insert(intervals, newInterval);
    cout << "----" << endl;
    for(int i=0;i<v.size();i++) {
        cout << v[i][0] << "-" << v[i][1] << endl;
    }

    return 0;
}