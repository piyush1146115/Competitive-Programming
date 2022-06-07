class Solution {
public:
    
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int row, col;
    
    
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        
        bool ret = false;
       
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                
                ret = dfs(i, j, 0, board, word);
                if(ret){
                    return true;
                }
            }
        }
        
        return ret;
    }
    
    
    bool dfs(int x, int y, int pos, vector<vector<char>>& board, string &word){
        if(pos == word.size())
            return true;
        
        if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] != word[pos])
            return false;
        
        board[x][y] = '$';
        
        bool ret = false;
        
       
        for(int i = 0; i < 4; i++){
            ret = dfs(x+dir[i][0], y+dir[i][1], pos+1, board, word);
            
            if(ret){
               return true; 
            }
        }
            
        
        board[x][y] = word[pos];
        
        return ret;
    }
};