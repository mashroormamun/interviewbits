#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    pair<int, int> getRowCol(int cell, int row_size) {
        return pair<int, int>(cell/row_size, cell%row_size);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col_size = matrix.size();
        int row_size = matrix[0].size();
        int s=0, e=col_size*row_size-1;

        while(s<=e) {
            int mid = (s+e)/2;
            cout << s << " " << mid << " " << e << endl;
            auto index = getRowCol(mid, row_size);
            if(matrix[index.first][index.second] == target) {
                return true;
            } else if(matrix[index.first][index.second] < target) {
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        return false;
    }
};

int main() {
    // vector<int> a = {1,3,5,7};
    // vector<int> b = {10,11,16,20};
    // vector<int> c = {23,30,34,60};
    // vector<vector<int>> matrix = {a,b,c};

    vector<int> a = {1};
    vector<vector<int>> matrix = {a};
    
    Solution s;
    cout << s.searchMatrix(matrix, 1) << endl;

    return 0;
}