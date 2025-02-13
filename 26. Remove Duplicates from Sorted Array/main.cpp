class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int currentNum = nums[0];
        int nextPtr = 1;

        for (int i=1 ; i< nums.size() ; i++) {
            if (currentNum == nums[i]) continue;

            currentNum = nums[nextPtr++] = nums[i];
        }

        return nextPtr;
    }
};
