#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while(start<end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k==0) return;

        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);

    }

    // void rotate(vector<int>& nums, int k) {
    //     k = k % nums.size();
    //     if (k==0) return;

    //     vector<int> res(nums.size());

    //     for (int i=0;i<nums.size();i++) {
    //         res[(i+k)%nums.size()] = nums[i];
    //     }

    //     nums=res;
    // }
};

int main() {
    Solution s;

    vector<int> v = {1,2,3,4,5,6,7};
    int k=3;

    s.rotate(v,k);

    for (auto it=v.begin(); it!=v.end(); it++) {
        cout << *it << " ";
    }
}