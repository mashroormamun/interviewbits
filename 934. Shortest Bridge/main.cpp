#include<iostream>
#include<set>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> direction{
                                pair<int, int>{ 1,  0},
                                pair<int, int>{-1,  0},
                                pair<int, int>{ 0,  1},
                                pair<int, int>{ 0, -1},
                            };

    void dfs(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visited) {
        int N = grid.size();

        if(r<0 ||  r>(N-1) || c<0 || c>(N-1)) return;
        if(grid[r][c] == 0) return;

        auto insert = visited.insert(pair<int, int>{r,c});
        if(insert.second) {
            for(auto dir=direction.begin(); dir!=direction.end(); dir++) {
                dfs(grid, r+dir->first, c+dir->second, visited);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;
        int N = grid.size();

        bool should_break = false;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(grid[i][j]==1) {
                    dfs(grid, i, j, visited);
                    should_break=true;
                    break;
                }
            }

            if(should_break) break;
        }
        

        queue<pair<int, int>> q;

        for(auto it=visited.begin(); it!=visited.end(); it++) {
            q.push(*it);
        }

        int step = 0;
        while(!q.empty()) {
            queue<pair<int, int>> new_q;

            while(!q.empty()) {
                auto cell = q.front();
                q.pop();

                for(auto dir=direction.begin(); dir!=direction.end(); dir++) {
                    int r = cell.first + dir->first;
                    int c = cell.second + dir->second;

                    if(r<0 ||  r>(N-1) || c<0 || c>(N-1)) continue;

                    auto check = visited.insert(pair<int,int>{r,c});
                    if(check.second == true) {
                        if(grid[r][c] == 1) return step;
                        
                        new_q.push(pair<int,int>{r,c});
                    }

                }
               
            }

            step++;
            q = new_q;
        }

        


        return step;
    }
};

int main() {
    // vector<vector<int>> grid = vector<vector<int>> {
    //     vector<int>{1,1,1,1,1},
    //     vector<int>{1,0,0,0,1},
    //     vector<int>{1,0,1,0,1},
    //     vector<int>{1,0,0,0,1},
    //     vector<int>{1,1,1,1,1},
    // };

    vector<vector<int>> grid = vector<vector<int>> {
        vector<int>{1,1},
        vector<int>{1,1},
        
    };

    // [0,1,0],[0,0,0],[0,0,1]

    Solution s;
    cout << s.shortestBridge(grid) << endl;

    return 0;
}