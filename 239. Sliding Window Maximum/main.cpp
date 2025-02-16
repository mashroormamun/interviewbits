#include <vector>
#include <iostream>

using namespace std;

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if(nums.size()<=1 || k==1) return nums;

//         vector<int> result;

//         for(int j=1;j<k;j++) {
//             for(int i=0; i<nums.size()-j; i++) {
//                 nums[i] = max(nums[i], nums[i+1]);

//                 if(j==(k-1)) {
//                     result.push_back(nums[i]);
//                 }
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()<=1 || k==1) return nums;

        vector<int> result;

        int max_index=-1;
        int max_num=INT32_MIN;

        for(int i=k-1;i>=0;i--) {
            if(nums[i]>max_num) {
                max_num=nums[i];
                max_index=i;
            }
        }

        result.push_back(max_num);

        int left=1;
        int right=k;

        while(right<nums.size()) {
            
            if(nums[right]>max_num) {
                max_index = right;
                max_num = nums[max_index];
                result.push_back(max_num);
            } else {
                if(left<=max_index && right>=max_index) {
                    result.push_back(max_num);
                } else {
                    max_num=INT32_MIN;

                    for(int i=right;i>=left;i--) {
                        if(nums[i]>max_num) {
                            max_num=nums[i];
                            max_index=i;
                        }
                    }

                    result.push_back(max_num);
                }
            }

            left++;
            right++;
        }

        return result;
    }
};

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k=3;

    Solution s;
    auto result = s.maxSlidingWindow(nums, k);

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}