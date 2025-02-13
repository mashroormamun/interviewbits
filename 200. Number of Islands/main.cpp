class Solution {
public:
    int islands = 0;

    void visitIsland(vector<vector<char>>& grid, int i, int j) {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()) {
            if(grid[i][j] == '1') {
                grid[i][j] = 0;
                visitIsland(grid, i+1, j);
                visitIsland(grid, i-1, j);
                visitIsland(grid, i, j+1);
                visitIsland(grid, i, j-1);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    visitIsland(grid, i, j);
                }
            }
        }

        return islands;
    }
};
