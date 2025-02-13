#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;

        for (int i=0; i<nums.size(); i++) {
            if(m.find(target-nums[i]) != m.end()) {
                result.push_back(i);
                result.push_back(m[target-nums[i]]);

                return result;
            }

            m[nums[i]] = i;
        }

        return result;
    }

    // brute force
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result;

    //     for (int i=0; i<nums.size()-1; i++) {
    //         for (int j=i+1; j<nums.size(); j++) {
    //             if (nums[i] + nums[j] == target) {
    //                 result.push_back(i);
    //                 result.push_back(j);

    //                 return result;
    //             }
    //         }
    //     }

    //     return result;
    // }
};

int main() {
    printf("hello world\n");

    Solution s;
    vector<int> sample {3,3};
    auto result = s.twoSum(sample, 6);

    for (int i=0; i<result.size(); i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}