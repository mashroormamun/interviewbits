#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea_bruteforce(vector<int> &heights) {
        int max = 0;

        for(int i=0; i<heights.size(); i++) {
            for(int j=i+1; j<heights.size(); j++) {
                int min_height = heights[i] > heights[j] ? heights[j] : heights[i];
                int capacity = min_height * (j-i);

                max = max < capacity ? capacity : max;
            }
        }

        return max;
    }

    int maxArea(vector<int> &heights) {
        int max = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right) {
            int min_height = heights[left] > heights[right] ? heights[right] : heights[left];
            int capacity = min_height * (right-left);
            max = max < capacity ? capacity : max;

            if(heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }

        }

        return max;
    }
};

int main() {
    Solution s;
    vector<int>v{1,7,2,5,4,7,3,6};

    cout << s.maxArea(v) << endl;
    return 0;
}