class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max=0;
        int start=0;
        int zero_count=0;

        for (int end=0; end<nums.size(); end++) {
            if (nums[end]==0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[start]==0) {
                    zero_count--;
                }

                start++;
            }

            max = max < (end-start+1) ? (end-start+1) : max;
        }

        return max;
    }
};