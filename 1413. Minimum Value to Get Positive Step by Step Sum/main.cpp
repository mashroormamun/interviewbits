class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min=0;
        int cumulative_sum = 0;

        for (int i=0; i<nums.size(); i++) {
            cumulative_sum += nums[i];

            if(cumulative_sum < min) min=cumulative_sum;
        }

        return abs(min)+1;
    }
};