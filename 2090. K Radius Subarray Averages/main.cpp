#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        fill(ans.begin(), ans.end(), -1);
        
        if (nums.size() <= 2*k) {
            return ans;
        }

        long long int sum=0;
        for (int i=0; i<=2*k; i++) {
            sum += nums[i];
        }

        for (int i=k; i<nums.size()-k; i++) {
            // cout << sum << endl;
            ans[i] = sum/(2*k+1);
            if ((i+k+1) < nums.size()) {
                sum = sum - nums[i-k] + nums[i+k+1];
                // cout << nums[i-k] << " <-> " << nums[i+k+1] << endl;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> v = {40527,53696,10730,66491,62141,83909,78635,18560};
    int k=2;

    auto ans = s.getAverages(v,k);

    for (auto it=ans.begin(); it!=ans.end(); it++) {
        cout << *it << " ";
    }
}