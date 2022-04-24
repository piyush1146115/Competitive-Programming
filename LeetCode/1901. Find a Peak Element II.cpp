class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size() - 1;
        
        while(startCol <= endCol){
            int midCol = (startCol + endCol)/2;
            
            int maxRow = 0;
            
            for(int row = 0; row < mat.size(); row++){
                maxRow = (mat[row][midCol] >= mat[maxRow][midCol])?row:maxRow;
            }
            
            bool leftMax = (midCol -1 >= startCol) && (mat[maxRow][midCol] <  mat[maxRow][midCol-1]);
            bool rightMax = (midCol + 1 <= endCol) && (mat[maxRow][midCol] < mat[maxRow][midCol + 1]);
            
            if(!leftMax && !rightMax)
                return {maxRow, midCol};
            
            if(leftMax)
                endCol = midCol - 1;
            else
                startCol = midCol + 1;
                
        }
        
        return {-1, -1};
    }
};