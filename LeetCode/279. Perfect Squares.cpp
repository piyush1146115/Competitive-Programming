class Solution {
public:
    vector<int> DP;
    int numSquares(int n) {
       
        DP = vector<int>(n+ 1, -1);
        int ans = dp(n);
        return ans;
    }
    
    int dp(int n)
    {
        if(n <= 0)
            return 0;
        
        if(DP[n] != -1)
            return DP[n];
        
        int ret = INT_MAX;
        
        for(int i = 1;i *i <= n; i++ ){
            ret = min(ret, 1 + dp(n - (i * i)));
        }
        DP[n] = ret;
        return ret;
    }
};