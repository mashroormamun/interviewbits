#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> L(height.size());
        vector<int> R(height.size());
        int trap = 0;

        L[0] = height[0];
        R[height.size()-1] = height[height.size()-1];

        for(int i=1;i<height.size();i++) {
            L[i] = height[i] > L[i-1] ? height[i] : L[i-1];
            R[height.size()-1-i] = height[height.size()-1-i] > R[height.size()-i] ? height[height.size()-1-i] : R[height.size()-i];
        }

        for(int i=0;i<height.size();i++) {
            int m = 0;

            if(i>0 && i<(height.size()-1)) {
                m = min(L[i-1], R[i+1]) - height[i];
                m = (m>0) ? m : 0;
                trap += m;
            }
        }

        return trap;
    }
};

int main() {
    Solution s;
    vector<int>v{0,2,0,3,1,0,1,3,2,1};

    cout << s.trap(v) << endl;
    return 0;
}