class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int max=0;
        int start=0;
        int allowed_zero_count=1;
        int zero_count=0;

        for (int end=0; end<nums.size(); end++) {
            if (nums[end]==0) {
                zero_count++;
            }

            while (zero_count > allowed_zero_count) {
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