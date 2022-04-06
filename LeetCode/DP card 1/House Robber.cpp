class Solution {
public:
    unordered_map<int,int>dp;
    
    int solve(int n, vector<int>& nums){
        if(n >= nums.size()){
            return 0;
        }    
        
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        
        dp[n] = max(nums[n] + solve(n+2, nums), solve(n+1,nums));
        
        return dp[n];
        
    }
    
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};