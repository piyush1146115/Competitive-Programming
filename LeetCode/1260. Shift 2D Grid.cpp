class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int> > ans(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int new_col = (j+k)%c;
                int wrap = (j+k)/c;
                int new_row = (i+wrap)%r;
                
                ans[new_row][new_col] = grid[i][j];
            }
        }
        
        return ans;
    }
};