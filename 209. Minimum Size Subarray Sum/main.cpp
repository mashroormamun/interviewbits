class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = nums[0];
        int size = nums.size();
        int min_len = INT_MAX;

        while(start<size) {
            if (sum >= target) {
                //cout << sum << " " << min_len << " " << (end-start+1) << endl;
                if(min_len > (end-start+1))
                    min_len = end-start+1;
            }
            //cout << sum << " " << min_len << endl;

            if(sum < target) {
                end++;
                if(end == size) {
                    if (min_len == INT_MAX)
                        return 0;
                    
                    return min_len;
                }
                sum += nums[end];
            } else if(sum >= target) {
                sum -= nums[start];
                start++;
            }
        }

        if (min_len == INT_MAX)
            return 0;
        
        return min_len;
    }
};
