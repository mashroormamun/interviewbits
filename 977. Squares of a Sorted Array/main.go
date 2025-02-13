class Solution {
public:
    static int firstNonNegativeIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if (nums[i] >= 0) {
                return i;
            }
        }

        return -1;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());

        int left = 0;
        int right = firstNonNegativeIndex(nums);
        if (right != -1) {
            left = right - 1;
        } else {
            left = nums.size()-1;
        }
        
        int index = 0;

        while(right<nums.size() && left >=0) {
            if(abs(nums[right] < abs(nums[left]))) {
                res[index++] = nums[right] * nums[right]; 
                right++;
            } else {
                res[index++] = nums[left] * nums[left]; 
                left--;
            }
        }

        while(left >= 0) {
            res[index++] = nums[left] * nums[left]; 
            left--;
        }

        while(right<nums.size()) {
            res[index++] = nums[right] * nums[right]; 
            right++;
        }

        return res;
    }
};
