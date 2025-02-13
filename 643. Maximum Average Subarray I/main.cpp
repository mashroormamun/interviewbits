class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max=0, sum=0;
        for (int i=0;i<k;i++) {
            max += nums[i];
        }

        sum = max;

        for (int i=1; i <= nums.size()-k; i++) {
            sum = sum - nums[i-1] + nums[i+k-1];
            if (sum>max) max = sum;
        }

        return (double)max/k;
    }
};