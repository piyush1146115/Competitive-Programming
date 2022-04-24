class Solution {
public:
    
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int dir[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        
        int cnt = 1;
        int row = 0;
        int col = 0;
        int d = 0;
        
        vector<int> res;
        
        while(cnt <= (m*n)){
            ++cnt;
            
            res.push_back(matrix[row][col]);
            
            matrix[row][col] = -1001;
            
            int r = floorMod(row + dir[d][0], m);
            int c = floorMod(col + dir[d][1], n);
            
            if(matrix[r][c] == -1001){
                d = (d+1)%4;
            }
            
            row += dir[d][0];
            col += dir[d][1];
        }
        
        return res;
    }
};