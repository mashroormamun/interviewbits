#include<iostream>
#include<set>
#include<vector>
#include<queue>

using namespace std;

// class Solution {
// public:
//     vector<pair<int, int>> direction{
//                                 pair<int, int>{ 1,  0},
//                                 pair<int, int>{-1,  0},
//                                 pair<int, int>{ 0,  1},
//                                 pair<int, int>{ 0, -1},
//                             };

//     void dfs(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visited) {
//         int N = grid.size();

//         if(r<0 ||  r>(N-1) || c<0 || c>(N-1)) return;
//         if(grid[r][c] == 0) return;

//         auto insert = visited.insert(pair<int, int>{r,c});
//         if(insert.second) {
//             for(auto dir=direction.begin(); dir!=direction.end(); dir++) {
//                 dfs(grid, r+dir->first, c+dir->second, visited);
//             }
//         }
//     }

//     int shortestBridge(vector<vector<int>>& grid) {
//         set<pair<int, int>> visited;
//         int N = grid.size();

//         bool should_break = false;

//         for(int i=0;i<N;i++) {
//             for(int j=0;j<N;j++) {
//                 if(grid[i][j]==1) {
//                     dfs(grid, i, j, visited);
//                     should_break=true;
//                     break;
//                 }
//             }

//             if(should_break) break;
//         }
        

//         queue<pair<int, int>> q;

//         for(auto it=visited.begin(); it!=visited.end(); it++) {
//             q.push(*it);
//         }

//         int step = 0;
//         while(!q.empty()) {
//             queue<pair<int, int>> new_q;

//             while(!q.empty()) {
//                 auto cell = q.front();
//                 q.pop();

//                 for(auto dir=direction.begin(); dir!=direction.end(); dir++) {
//                     int r = cell.first + dir->first;
//                     int c = cell.second + dir->second;

//                     if(r<0 ||  r>(N-1) || c<0 || c>(N-1)) continue;

//                     auto check = visited.insert(pair<int,int>{r,c});
//                     if(check.second == true) {
//                         if(grid[r][c] == 1) return step;
                        
//                         new_q.push(pair<int,int>{r,c});
//                     }

//                 }
               
//             }

//             step++;
//             q = new_q;
//         }

        


//         return step;
//     }
// };
static void print(vector<vector<int>>& grid) {
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

class Solution {
public:
    int visited = -1;
    vector<vector<int>> direction { {0,1}, {0,-1}, {1,0}, {-1,0} }; 
    
    pair<int, int> findIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    return pair{i,j};
                }
            }
        }

        return pair{-1, -1};
    }

    void firstIsland(vector<vector<int>>& grid, int r, int c, queue<pair<int,int>> &q) {
        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size()) {
            if(grid[r][c]==1) {
                grid[r][c]=visited;
                q.push({r,c});

                for(int i=0;i<direction.size();i++) {
                    firstIsland(grid, r+direction[i][0], c+direction[i][1], q);
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        auto row_col = findIsland(grid);
        int bridge = 0;

        if(row_col.first!=-1 && row_col.second!=-1) {  

            queue<pair<int,int>> q;
            firstIsland(grid, row_col.first, row_col.second, q);

            queue<pair<int,int>> new_nodes;
            
            while(!q.empty()) {
                print(grid);
                while(!q.empty()) {
                    auto node = q.front();
                    q.pop();

                    for(int i=0;i<direction.size();i++) {
                        int r = node.first + direction[i][0];
                        int c = node.second + direction[i][1];

                        if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size()) {
                            if(grid[r][c]==1) return bridge;

                            if(grid[r][c] != visited) {
                                new_nodes.push({r,c});
                                grid[r][c] = visited;
                            }
                        }

                    }                
                }

                q = new_nodes;
                bridge++;
            }

        } 
        
        return -1;
    }
};



int main() {
    vector<vector<int>> grid = vector<vector<int>> {
        vector<int>{0,0,0,1,1},
        vector<int>{0,0,0,1,1},
        vector<int>{0,0,0,0,0},
        vector<int>{1,1,0,0,0},
        vector<int>{1,1,0,0,0},
    };

    // vector<vector<int>> grid = vector<vector<int>> {
    //     vector<int>{1,1},
    //     vector<int>{1,1},
        
    // };

    // [0,1,0],[0,0,0],[0,0,1]

    Solution s;
    cout << s.shortestBridge(grid) << endl;

    print(grid);

    return 0;
}