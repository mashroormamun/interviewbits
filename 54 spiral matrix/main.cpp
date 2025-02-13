#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    enum direction
    {
        right,
        down,
        left,
        up
    };

    direction getNextDirection(direction currectDirection) {
        return (direction)((currectDirection+1)%4);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        direction currectDirection = direction::right;

        int row = matrix.size();
        int col = matrix[0].size();

        if(col==1) currectDirection = direction::down;
        
        vector<int> result;

        int r=0,c=0;
        int VISITED_FLAG = -999;
        result.push_back(matrix[r][c]);
        matrix[r][c]=VISITED_FLAG;

        for (int i=0;i<row*col-1;i++) {
            switch(currectDirection) {
                case direction::right:
                c++;
                result.push_back(matrix[r][c]);
                matrix[r][c]=VISITED_FLAG;
                if(c==col-1) {
                    currectDirection = getNextDirection(currectDirection);
                } else if (matrix[r][c+1]==VISITED_FLAG) {
                    currectDirection = getNextDirection(currectDirection);
                }
                break;

                case direction::down:
                r++;
                result.push_back(matrix[r][c]);
                matrix[r][c]=VISITED_FLAG;
                if(r==row-1) {
                    currectDirection = getNextDirection(currectDirection);
                } else if (matrix[r+1][c]==VISITED_FLAG) {
                    currectDirection = getNextDirection(currectDirection);
                }
                break;

                case direction::left:
                c--;
                result.push_back(matrix[r][c]);
                matrix[r][c]=VISITED_FLAG;
                if(c==0) {
                    currectDirection = getNextDirection(currectDirection);
                } else if (matrix[r][c-1]==VISITED_FLAG) {
                    currectDirection = getNextDirection(currectDirection);
                }
                break;

                case direction::up:
                r--;
                result.push_back(matrix[r][c]);
                matrix[r][c]=VISITED_FLAG;
                if(r==0) {
                    currectDirection = getNextDirection(currectDirection);
                } else if (matrix[r-1][c]==VISITED_FLAG) {
                    currectDirection = getNextDirection(currectDirection);
                }
                break;
            }
        }

        return result;
    }
};

int main() {
    vector<int> a = {1,2,3,4};
    vector<int> b = {5,6,7,8};
    vector<int> c = {9,10,11,12};

    vector<vector<int>> mat = {a,b,c};

    Solution s;
    auto res = s.spiralOrder(mat);

    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "\n\n" << endl;

    for (int i=0;i<res.size();i++) {
        cout << res[i] << " " ;
    }

    return 0;
}