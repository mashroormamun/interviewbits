#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size());
        vector<vector<int>>res;

        for(int i=0;i<n;i++) {
            vector<int>temp_res;
            int row = i;

            for(int j=0;j<nums.size();j++) {
                if((row&1)==1) {
                    temp_res.push_back(nums[j]);
                }

                row = row >> 1;
            }

            res.push_back(temp_res);
        }

        return res;
    }
};

int main() {
    vector<int> v{1,2,3};

    Solution s;
    auto res = s.subsets(v);

    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}