// space O(m+n)
class Solution {
public:
    void setRowZeroes(vector<vector<int>>& matrix, int row) {
        for (int i=0;i<matrix[0].size();i++) {
            matrix[row][i] = 0;
        }
    }

    void setRowColumnZeroes(vector<vector<int>>& matrix, int col) {
        for (int i=0;i<matrix.size();i++) {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r_z;
        set<int> c_z;

        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix[i].size();j++) {
                if (matrix[i][j] == 0) {
                    r_z.insert(i);
                    c_z.insert(j);
                }
            }
        }

        for(auto it=r_z.begin();it!=r_z.end(); it++) {
            setRowZeroes(matrix, *it);
        }

        for(auto it=c_z.begin();it!=c_z.end(); it++) {
            setRowColumnZeroes(matrix, *it);
        }
    }
};

// space O(m*n)
// class Solution {
// public:
//     void setRowColumnZeroes(vector<vector<int>>& matrix, int row, int col) {
//         for (int i=0;i<matrix.size();i++) {
//             matrix[i][col] = 0;
//         }

//         for (int i=0;i<matrix[0].size();i++) {
//             matrix[row][i] = 0;
//         }
//     }

//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<pair<int, int>> z_loc;

//         for (int i=0;i<matrix.size();i++) {
//             for (int j=0;j<matrix[i].size();j++) {
//                 if (matrix[i][j] == 0) {
//                     z_loc.push_back(pair<int,int>{i,j});
//                 }
//             }
//         }

//         for(int i=0;i<z_loc.size(); i++) {
//             setRowColumnZeroes(matrix, z_loc[i].first, z_loc[i].second);
//         }
//     }
// };
