class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        
        for(int i=nums.size()-2; i>=0; i--) {
            if (nums[i]+i >= goal) goal = i;
        }

        if (nums[0] >= goal) return true;

        return false;
    }
};
