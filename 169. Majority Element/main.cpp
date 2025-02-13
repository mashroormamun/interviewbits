#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=nums[0];
        int count=1;

        for (int i=1;i<nums.size();i++) {
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                major = nums[i];
                count = 1;
            }
        }

        return major;
    }
};

int main() {
    vector<int> v={1,1,1,2,2,3,1};
    Solution s;
    int n = s.majorityElement(v);

    cout << n << endl;
   
}