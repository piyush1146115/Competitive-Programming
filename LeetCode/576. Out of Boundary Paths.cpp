class Solution {
public:
    int MOD = 1e9 + 7;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int possiblePaths(int row, int col, int maxMove, int x, int y,vector<vector<vector<int>>> &paths ){
            
            if(x < 0 || y < 0 || x >= row || y >= col)
                return 1;
        
            if(maxMove == 0)
                return 0;
        
            if(paths[maxMove][x][y] != -1)
                return paths[maxMove][x][y];
        
        long long sum = 0;
        
        for(int i = 0; i < 4; i++){
            sum = (sum + possiblePaths(row, col, maxMove-1, x+dir[i][0], y+dir[i][1], paths)) % MOD;
            
        }
        paths[maxMove][x][y] = sum;
        
        
        return paths[maxMove][x][y];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> paths(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        return possiblePaths(m, n, maxMove, startRow, startColumn, paths);
    }
};