class Solution {
public:
    
    int m, n;
    int DP[1005][1005];
    
    int solve(int cur, int left, vector<int>& nums, vector<int>& multipliers)
    {
        if(cur >= m){
            return 0;
        }
        
        if(DP[cur][left] != -1){
            return DP[cur][left];
        }
        
        int right = n - 1 - (cur - left);
        int mul = multipliers[cur];
        
        
        int ret = max((nums[left]*mul) + solve(cur+1, left+1, nums, multipliers),
                      (nums[right]*mul) + solve(cur+1, left, nums, multipliers));
        
        
        DP[cur][left] = ret;
        return ret;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        m = multipliers.size();
        n = nums.size();
        
        memset(DP, -1, sizeof(DP));
        
        return solve(0,0,nums,multipliers);
    }
};