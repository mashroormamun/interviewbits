class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currentPtr = 0;
        int len = nums.size();

        for (int i=0 ; i<len ; i++) {
            if(nums[i] != val) {
                nums[currentPtr++] = nums[i];
            }
        }

        return currentPtr;
    }
};
