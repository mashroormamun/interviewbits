class Solution {
public:
    vector<vector<int>> direction{{0,1}, {0,-1}, {1,0},{-1,0}};
    
    void findAndDeleteIsland(int r, int c, vector<vector<int>>& grid, int row, int col, int &area) {
        if(r<0 || r>=row) return;
        if(c<0 || c>=col) return;
        
        if(grid[r][c]==1){
            grid[r][c]=0;
            area++;

            for(int i=0;i<direction.size();i++) {
                findAndDeleteIsland(r+direction[i][0], c+direction[i][1], grid, row, col, area);
            } 
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int area=0;
        int max_area=0;
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]==1) {
                    int area=0;
                    findAndDeleteIsland(i, j, grid, row, col, area);
                    
                    max_area = area > max_area ? area : max_area;
                }
            }
        }
        
        return max_area;
    }
};
