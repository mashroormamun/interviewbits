class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int combination_num = pow(2, nums.size());
        vector<vector<int>> v;
        
        for(int i=0;i<combination_num;i++) {
            vector<int> entry;
            
            for(int j=nums.size()-1;j>=0;j--) {
                if ((i>>j)&1 == 1) {
                    entry.push_back(nums[j]);
                }
            }
            
            v.push_back(entry);
        }
        
        return v;
    }
};


/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int combination_num = pow(2, nums.size());
        set<vector<int>> s; // set not needed as the input will be unique
        
        for(int i=0;i<combination_num;i++) {
            vector<int> entry;
            
            for(int j=nums.size()-1;j>=0;j--) {
                if ((i>>j)&1 == 1) {
                    entry.push_back(nums[j]);
                }
            }
            
            s.insert(entry);
        }
        
        vector<vector<int>> v(s.begin(), s.end());
        
        return v;
    }
};
*/
