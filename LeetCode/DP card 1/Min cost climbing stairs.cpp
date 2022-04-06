class Solution {
public:
    unordered_map<int, int> dp;
    
    int solve(int n, vector<int>& cost){
        if(n >= cost.size()){
            return 0;
        }    
        
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        
        dp[n] = cost[n] +  min(solve(n+1, cost), solve(n+2, cost));
        
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(0, cost), solve(1, cost));
    }
};