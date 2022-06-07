class Solution {
public:
    int row, col, cnt;
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis){
        cnt++;
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            
            if(xx >= 0 && yy >= 0 && xx < row && yy < col && grid[xx][yy]== 1 && vis[xx][yy] == 0){
                dfs(xx, yy, grid, vis);
            }
        }
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int> > vis(row, vector<int>(col, 0));
        int ans = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    cnt = 0;
                    dfs(i, j, grid, vis);
                    ans = max(ans, cnt);
                }
            }
        }
        
        return ans;
        
    }
};