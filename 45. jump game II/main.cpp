#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;

        for(int i=0; i<nums.size(); i++) {
            for(int j=1; j<=nums[i] && (i+j)<nums.size() ;j++) {
                if((dp[i]+1) < dp[i+j]) {
                    dp[i+j] = dp[i]+1;
                }
            }

            // for(int k=0; k<dp.size(); k++) {
            //     cout << dp[k] << " ";
            // }
            // cout << endl;
        }

        

        return dp[nums.size()-1];
    }
};

int main() {
    vector<int> input{2,3,1,1,4};

    Solution s;
    s.jump(input);

    return 0;
}