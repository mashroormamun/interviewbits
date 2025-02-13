#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0;i<nums.size();i++) {
            minHeap.push(nums[i]);

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();

    }
};

int main() {
    vector<int> v{2,3,1,1,5,5,4};
    Solution s;

    cout << s.findKthLargest(v,3) << endl;

    return 0;
}