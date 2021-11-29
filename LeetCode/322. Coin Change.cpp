class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 3];
        dp[0] = 0;
        
        sort(coins.begin(), coins.end());
        
        for(int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            
            for(int j = 0; j < coins.size(); j++){
                if((i - coins[j]) < 0)
                    break;
                
                if(dp[i - coins[j]] == INT_MAX)
                    continue;
                
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        
        if(dp[amount] == INT_MAX)
            return -1;
        
        return dp[amount];
    }
};