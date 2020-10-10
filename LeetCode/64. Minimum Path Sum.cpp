class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        int col = grid[0].size();
        int add;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                 add = INT_MAX;
                if(i != 0)
                    add = min(add, grid[i - 1][j]);
                
                if(j != 0)
                    add = min(add, grid[i][j - 1]);
                
                if(add == INT_MAX)
                    add = 0;
                
                grid[i][j] += add;
            }
        }
        return grid[row - 1][col - 1];
    }

};