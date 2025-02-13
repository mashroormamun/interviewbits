class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> m;

        for(int i=0;i<nums.size();i++) {
            m[nums[i]] += 1;

            if (m[nums[i]] == 2) 
                return true;
        }

        return false;
    }
};

