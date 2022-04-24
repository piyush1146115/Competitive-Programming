class Solution {
public:
    int row = 9, col = 9;
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < row; i++){
            vector<int> cnt(10, 0);
            
            for(int j = 0; j < col; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                
                cnt[board[i][j] - '0']++;
                if(cnt[board[i][j] - '0'] > 1)
                    return false;
            }
        }
        
        for(int i = 0; i < col; i++){
            vector<int> cnt(10, 0);
            
            for(int j = 0; j < row; j++){
                
                if(board[j][i] == '.'){
                    continue;
                }
                
                cnt[board[j][i] - '0']++;
                if(cnt[board[j][i] - '0'] > 1)
                    return false;
            }
        }
        
        
        for(int i = 0; i < row; i += 3){
            for(int j = 0; j < col; j += 3){
                vector<int> cnt(10, 0);
                
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i+k][j+l] == '.')
                            continue;
                        
                        int num = board[i+k][j+l] - '0';
                        
                         cnt[num]++;
                        if(cnt[num] > 1)
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};