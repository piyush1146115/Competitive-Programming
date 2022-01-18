class Solution {
public:
    int lcs(int pos1, int pos2, vector<vector<int> > &dp, string &text1, string &text2){
        if(pos1 >= text1.size() || pos2 >= text2.size())
            return 0;
        
        if(dp[pos1][pos2] != -1)
            return dp[pos1][pos2];
        
        int res = 0;
        if(text1[pos1] == text2[pos2]){
            res = 1 + lcs(pos1+1, pos2+1, dp, text1, text2);
        }
        else{
            res = max(lcs(pos1+1, pos2, dp, text1, text2), lcs(pos1, pos2+1, dp, text1, text2));
        }
        
        dp[pos1][pos2] = res;
        return res;
    }
    
    int longestCommonSubsequence(string text1, string text2) {

        // Recursive
        //vector<vector<int> > dp(text1.size()+2, vector<int>(text2.size()+2, -1));
        
        //return lcs(0, 0, dp, text1, text2);
        

        // Iterative
        vector<vector<int> > dp(text1.size()+2, vector<int>(text2.size()+2, 0));
        
        for(int i = text1.size() -1 ; i >= 0; i--){
            for(int j = text2.size() - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};