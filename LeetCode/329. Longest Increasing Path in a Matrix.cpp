class Solution {
public:
    int row, col;
    vector<vector<int>> DP;
    
    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    
    int LIP(int x, int y, vector<vector<int>> &matrix){
            if(DP[x][y] != -1)
                return DP[x][y];
        int ret = 1;
        
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            
            if(xx >= 0 && yy >= 0 && xx < row && yy < col && matrix[xx][yy]>matrix[x][y]){
                ret = max(ret, 1+LIP(xx,yy,matrix));
            }
        }
        
        DP[x][y] = ret;
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        
        DP = vector<vector<int> >(row, vector<int>(col, -1));
        int ans = 0;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(DP[i][j] == -1){
                    ans = max(ans,LIP(i, j, matrix));            
                }else{
                    ans = max(ans, DP[i][j]);
                }
            }
        }
        
        return ans;
        
    }
};