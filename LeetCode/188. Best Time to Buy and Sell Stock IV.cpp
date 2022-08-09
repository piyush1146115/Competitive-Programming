class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          vector<vector<int>> DP(k+1, vector<int>(prices.size() + 1, 0));
        
         if (prices.size() == 0) return 0;
        
            for (int K = 1;K <=k; K++) {
                int mn = prices[0];
                for (int i = 1; i < prices.size(); i++) {
                    mn = min(mn, prices[i] - DP[K-1][i-1]);
                    
                    DP[K][i] = max(DP[K][i-1], prices[i] - mn);
                }
            }

            return DP[k][prices.size() - 1]; 
    }
};