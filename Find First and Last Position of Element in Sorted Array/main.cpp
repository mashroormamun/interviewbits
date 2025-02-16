#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int target, bool find_left) {
        int left = 0;
        int right = nums.size()-1;
        int result = -1;
        
        while(left<=right) {
            int mid = left + (right-left)/2;

            cout << mid << endl;
            
            if(nums[mid]==target) {
                result=mid;
                if(find_left) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
            else if(nums[mid]<target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return result;
    }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {binary_search(nums, target, true),binary_search(nums, target, false)};
        
    }
};

int main() {
    Solution s;
    vector<int> nums{5,7,7,8,8,10};

    auto r = s.searchRange(nums, 8);

    cout << r[0] << " " << r[1] << endl;

    return 0;
}