class Solution {
public:
    
    bool solve(int n, vector<int>& DP){
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(DP[n] != -1){
            return DP[n];
        }
        
        bool ret = false;
        
        for(int i = 1; i*i <= n; i++){
            ret = ret | (!solve(n - i*i, DP));
        }
        
        DP[n] = ret;
        return ret;
    }
    
    
    bool winnerSquareGame(int n) {
        vector<bool> DP(n + 5, false);
        //return solve(n, DP);
        
        DP[1] = true;
        DP[0] = false;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                if(!DP[i- j*j]){
                    DP[i] = true;
                    break;
                }
            }
        }
        
        return DP[n];
    }
};