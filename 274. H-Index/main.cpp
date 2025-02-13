#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        // using binary search to make more efficient
        int s=0, e=citations.size();
        while(e!=s+1) {
            int mid = (s + e)/2;
            if(citations[mid] == (mid+1)) {
                return mid;
            }

            if(citations[mid] > (mid+1)) {
                s = mid;
            } else {
                e = mid;
            }
        }

        for (int i=s;i<citations.size(); i++) {
            if (i+1 > citations[i]) return i;
        }

        return citations.size();
    }
};


int main() {
    vector<int> v = {0,1,2,2,2,7,9};
    Solution s;
    cout << s.hIndex(v) << endl;
}

// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(), citations.end(), greater<int>());

//         for (int i=0;i<citations.size(); i++) {
//             if (i+1 > citations[i]) return i;
//         }

//         return citations.size();
//     }
// };
