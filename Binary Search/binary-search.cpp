class Solution {
public:
    int binarysearch(vector<int>& nums, int target, int left, int right) {
        if(left>right) return -1;
        
        int mid = left + (right-left)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        return binarysearch(nums, target, left, right);
    }

    int search(vector<int>& nums, int target) {
        return binarysearch(nums, target, 0, nums.size()-1);
    }
};

