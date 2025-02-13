class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_index = -1;
        int zero_count = 0;
        long long int product = 1;

        vector<int> ans(nums.size(), 0);

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                zero_index = i;
                zero_count++;
                if (zero_count > 1) {
                    return ans;
                }
            } else {
                product *= nums[i]; 
            }
        }

        if(zero_count > 0) {
            ans[zero_index] = product;
            return ans;
        } else {
            for(int i=0; i<nums.size(); i++) {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
