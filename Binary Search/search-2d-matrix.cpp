class Solution {
public:
    bool binarysearch(vector<vector<int>>& nums, int target, int left, int right, int c) {
        if(left>right) return false;

        int mid = left + (right-left)/2;

        int converted_row = mid/c;
        int converted_col = mid%c;

        if(nums[converted_row][converted_col] == target)
            return true;

        if(nums[converted_row][converted_col] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        return binarysearch(nums, target, left, right, c);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0) return false;

        int c = matrix[0].size();

        return binarysearch(matrix, target, 0, r*c-1, c);
    }
};

