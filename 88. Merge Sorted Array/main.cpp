#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m==0) {
            nums1 = nums2;
            return;
        }

        int nums1_ptr = m-1;
        int nums2_ptr = n-1;
        int index = nums1.size()-1;

        while (nums2_ptr >= 0 && nums1_ptr >= 0) {
            // cout << index << nums1_ptr << nums2_ptr << endl;

            if (nums1[nums1_ptr] > nums2[nums2_ptr]) {
                nums1[index--]=nums1[nums1_ptr--];
            } else {
                nums1[index--]=nums2[nums2_ptr--];
            }
        }

        while (nums2_ptr >= 0) {
            nums1[index--]=nums2[nums2_ptr--];
        }
    }
};

int main() {
    Solution s;

    vector<int> a = {2,0};//{1,2,3,0,0,0};
    vector<int> b = {1};//{2,5,6};

    s.merge(a,1,b,1);

    for (auto it=a.begin(); it!=a.end(); it++) {
        cout << *it << " ";
    }
}