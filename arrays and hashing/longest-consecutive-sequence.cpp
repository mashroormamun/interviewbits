class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int max = 0;

        for(int i=0;i<nums.size();i++) s.insert(nums[i]);

        for(int i=0;i<nums.size();i++) {
            int number = nums[i];

            if( s.find(number-1) != s.end()) {
                continue;
            }

            int count = 0;
            while(s.find(number++) != s.end()) {
                count++;
            }

            max = (max > count) ? max : count;
        }
        
        return max;
    }
};

