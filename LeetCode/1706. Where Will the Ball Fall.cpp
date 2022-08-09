class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < col; i++){
            int curRow = 0;
            int curCol = i;
            
            bool stuck = false;
            
            while(curRow < row && !stuck){
                if(curCol == 0 && grid[curRow][0] == -1)
                    stuck = true;
                else if(curCol == col-1 && grid[curRow][curCol] == 1)
                    stuck = true;
                else if(curCol < col-1 && grid[curRow][curCol] == 1 && grid[curRow][curCol+1] == -1)
                    stuck = true;
                else if(curCol > 0 && grid[curRow][curCol] == -1 && grid[curRow][curCol-1] == 1)
                    stuck = true;
                else{
                    curCol += grid[curRow][curCol];
                    curRow++;
                }
            }
            
            if(stuck){
                ans.push_back(-1);
            }
            else{
                ans.push_back(curCol);
            }
        }
        
        return ans;
    }
};