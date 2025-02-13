#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();    
        int nums2_size = nums2.size();
        vector<int> res;

        int total_size = nums1_size + nums2_size;
        
        bool is_even = false;
        if(total_size%2 == 0) {
            is_even = true;
        }

        //is_even == true : avg of total_size/2 and (total_size/2)+1
        //is_even == false : total_size/2+1

        int nums1_index = 0;
        int nums2_index = 0;
        int itr = 1;

        cout << "==\t1\t==" << endl;

        while (nums1_index<nums1_size && nums2_index<nums2_size) {
            if(nums1[nums1_index] < nums2[nums2_index]) {
                if(is_even) {
                    if(itr == (total_size/2+1) || itr == (total_size/2)) res.push_back(nums1[nums1_index]);
                } else if (itr == (total_size/2+1)) {
                    return (double)nums1[nums1_index];
                }
                nums1_index++;
            } else {
                if(is_even) {
                    if(itr == (total_size/2+1) || itr == (total_size/2)) res.push_back(nums2[nums2_index]);
                    nums2_index++;
                } else if (itr == (total_size/2+1)){
                    return (double)nums1[nums1_index];
                }
            }

            itr++;
        }

        cout << "==\t2\t==" << endl;

        if(!is_even && res.size()==1) return res[0];
        if(is_even && res.size()==2) return (double)(res[0]+res[1])/2;

        cout << "==\t3\t==" << endl;

        if(nums1_index<nums1_size) {
            nums1_index += ((total_size/2)+1) - itr;
            if(is_even)
                res.push_back(nums1[nums1_index-1]);
            res.push_back(nums1[nums1_index]);
            
        }

        cout << "==\t4\t==" << endl;

        if(nums2_index<nums2_size) {
            nums2_index += ((total_size/2)+1) - itr;
            if(is_even)
                res.push_back(nums2[nums2_index-1]);
            res.push_back(nums2[nums2_index]);
        }

        cout << "==\t5\t==" << endl;

        if(res.size()==0)   
            return 0;

        cout << "==\t6\t==" << endl;

        if(!is_even) return (double)res[0];

        cout << "==\t7\t==" << endl;

        if(is_even) return (double)(res[0]+res[1])/2;

        return 0;
    }
};


int main() {
    Solution s;
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};

    cout << s.findMedianSortedArrays(v1, v2) << endl;

    return 0;
}