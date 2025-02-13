#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
      
        while(start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                return vector<int> {start+1, end+1};
            } else if(sum < target) {
                start++;
            } else {
                end--;
            }
        }

        return vector<int> {};
    }
};

// // Binary search got TLE
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
        
//         for(int i=1; i<numbers.size(); i++) {
//             // cout << i << endl;

//             int index = binarySearch(numbers, 0, i-1, otherTarget);
//             if (index != -1) {
//                 return vector<int> {index+1, i+1};
//             }
//         }
        
//         return vector<int> {};
//     }

//     int binarySearch(vector<int>& numbers, int start, int end, int target) {
//         // cout << start << " " << end << endl;
//         if(start >= end) {
//             if (numbers[start] == target) return start;
//             return -1;
//         }
            
//         int middle = (start + end) / 2;
//         if (numbers[middle] == target) return middle;

//         // cout << start << " " << end << endl;
//         cout << numbers[middle] << endl;

//         if (numbers[middle] < target) {
//             return binarySearch(numbers, middle+1, end, target);
//         } else {
//             return binarySearch(numbers, start, middle-1, target);
//         }

//     }
// };

int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;

    Solution s;
    auto res = s.twoSum(numbers, target);
    cout << res[0] << " " << res[1] << endl;

    // auto res = s.binarySearch(numbers, 0, numbers.size()-1, target);
    // cout << res << endl;


    return 0;
}