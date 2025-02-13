#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:


    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
        vector<vector<int>> result;
        
        bool mergingStarted = false;
        bool isNewIntervalPushed = false;

        for(int i=0; i<intervals.size(); i++) {
            cout << i << endl;
            if(!isNewIntervalPushed) {
                if(newInterval[0] < intervals[i][0]) {
                    cout << "aaaa" << endl;
                    
                    if(newInterval[1] >= intervals[i][0]) {
                        cout << "bbbbb" << endl;
                        newInterval[1] = max(newInterval[1], intervals[i][1]);
                        mergingStarted = true;
                    } else {
                        cout << "cccc" << endl;
                        if(mergingStarted) {
                            result.push_back(newInterval);
                            isNewIntervalPushed = true;
                            mergingStarted=false;
                        }

                        result.push_back(intervals[i]);
                    }

                } else {
                    cout << "dddd" << endl;
                    if(newInterval[0] <= intervals[i][1]) {
                        cout << "eeee" << endl;
                        newInterval[0] = intervals[i][0];
                        newInterval[1] = max(newInterval[1], intervals[i][1]);
                        mergingStarted = true;
                    } else {
                        cout << "ffff" << endl;
                        if(mergingStarted) {
                            result.push_back(newInterval);
                            isNewIntervalPushed = true;
                            mergingStarted=false;
                        }

                        result.push_back(intervals[i]);
                    }

                }
            } else {
                result.push_back(intervals[i]);
            }
        }

        if(result.size()==0 || isNewIntervalPushed == false)
            result.push_back(newInterval);

        sort(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution s;
    // [[1,3],[2,6],[8,10],[15,18]]
    auto ans = s.insert(vector<vector<int>> {
        vector<int>{1,2},
        vector<int>{3,5},
        vector<int>{6,7},
        vector<int>{8,10},
        vector<int>{12,16},
    }, vector<int>{6,8});

    for(int i=0;i<ans.size();i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}