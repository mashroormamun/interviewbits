#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int currentNum = nums[0];
        int currentNumCount = 1;
        int nextPtr = 1;

        for (int i=1 ; i< nums.size() ; i++) {
            if (currentNum == nums[i]) {
                currentNumCount++;

                if (currentNumCount>2)
                    continue;
            } else {
                currentNumCount=1;
            }

            
            currentNum = nums[nextPtr++] = nums[i];
        }

        return nextPtr;
    }
};

int main() {
    vector<int> v={1,1,1,2,2,3};
    Solution s;
    int n = s.removeDuplicates(v);

    cout << n << endl;
    for(auto it=v.begin();it!=v.end();it++) {
        cout << *it << " " ;
    }
}