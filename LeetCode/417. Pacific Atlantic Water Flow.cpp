class Solution {
public:
    
    int row, col;
    
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>> &vis){
        
        int xx, yy;
        vis[x][y] = true;
        
        for(int i = 0; i < 4; i++){
            xx = x + dir[i][0];
            yy = y + dir[i][1];
            
            if(xx >= 0 && yy >=0 && xx < row && yy < col && vis[xx][yy] == false && heights[xx][yy] >= heights[x][y]){
                dfs(xx,yy,heights,vis);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        
        vector<vector<bool> > pac(row, vector<bool>(col, false));
        
        for(int i = 0; i < col; i++){
            dfs(0, i, heights, pac);
        }
        
        for(int i = 0; i < row; i++){
            dfs(i, 0, heights, pac);
        }
        
        vector<vector<bool> > atl(row, vector<bool>(col, false));
        
        for(int i = 0; i < col; i++){
            dfs(row-1, i, heights, atl);
        }
        
        for(int i = 0; i < row; i++){
            dfs(i, col-1, heights, atl);
        }
        
        vector<vector<int>> ret;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pac[i][j] && atl[i][j]){
                    ret.push_back({i,j});
                }
            }
        }
        
        return ret;
    }
};