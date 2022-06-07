class Solution {
public:
    vector<vector<int>> DP;
    
    int ways(int pos, int amount, vector<int>& coins){
        if(amount == 0){
            return 1;
        }
        if(pos == coins.size() || amount < 0){
            return 0;
        }
        
        if(DP[amount][pos] != -1)
            return DP[amount][pos];
        
        int ret = ways(pos, amount-coins[pos], coins);
        ret += ways(pos+1, amount, coins);
        
        DP[amount][pos] = ret;
        
        return ret;
    }
    
    int change(int amount, vector<int>& coins) {
        
//         DP = vector<vector<int>>(amount+1, vector<int>(coins.size() + 1, -1));
        
//         int ans = ways(0, amount, coins);
//         return ans;
        
    vector<int> dp(amount+1,0);
    dp[0] = 1;

    for (auto coin : coins) {
      for (int x = coin; x < amount + 1; ++x) {
        dp[x] += dp[x - coin];
      }
    }
    return dp[amount];
    }
};