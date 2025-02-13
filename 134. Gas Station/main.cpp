#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> remain(gas.size());

        for(int i=0; i<remain.size(); i++) {
            remain[i] = gas[i] - cost[i];
        }

        int index = 0;
        int sum = 0;
        bool problem = false;

        for(int i=0; i<remain.size(); i++) {
            sum += remain[i];

            // cout << sum << " " << index << endl;

            if (problem && sum>=0) {
                index = i;
                problem = false;
            }

            if (sum < 0) {
                problem = true;
                sum = 0;
            }
        }

        sum = 0;
        for(int i=0; i<remain.size(); i++) {
            int target = (index+i)%remain.size();
            sum += remain[target];
        }

        if (sum < 0) return -1;

        return index;
    }
};

// // TLE
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         vector<int> remain(gas.size());

//         for(int i=0; i<remain.size(); i++) {
//             remain[i] = gas[i] - cost[i];
//         }

//         for(int i=0; i<remain.size(); i++) {
//             int sum = 0;

//             for(int j=0; j<remain.size(); j++) {
//                 int index = (i+j)%remain.size();
//                 sum += remain[index];

//                 if(sum < 0) break;

//                 if(j==(remain.size()-1)) {
//                     return i;
//                 }
//             }
//         }

//         return -1;
//     }
// };

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    // vector<int> gas = {2,3,4};
    // vector<int> cost = {3,4,3};
    // vector<int> gas = {3,1,1};
    // vector<int> cost = {1,2,2};

    Solution s;
    int index = s.canCompleteCircuit(gas, cost);

    cout << index << endl;
}