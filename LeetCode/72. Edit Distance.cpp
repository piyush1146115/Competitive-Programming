class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<vector<int> > Dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++)
            Dp[i][0] = i;
        
        for(int i = 0 ; i <= m; i++)
            Dp[0][i] = i;
        
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    Dp[i][j] = Dp[i-1][j - 1];
                }
                else{
                    Dp[i][j] = min(Dp[i][j - 1], min(Dp[i - 1][j -1], Dp[i - 1][j])) + 1;
                }
            }
        }
        
        return Dp[n][m];
        
    }
};