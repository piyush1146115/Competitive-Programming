class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int> > DP;
    int countOrders(int n) {
        
//         long long int ans = 1;
        
//         for(long int i = 1; i <= n; i++){
//             ans *= i;
            
//             ans *= (2*i - 1);
            
//             ans %= MOD;
//         }
        
//       //  cout << ans << endl;
//         return ans;
        
       DP = vector<vector<int> > (n + 2, vector<int>(n + 2, 0));
        
        return (int)ways(n, n);
    }
    
    long ways(int unpicked, int undelivered){
        if(unpicked == 0 && undelivered == 0)
            return 1;
        
        if(unpicked < 0 || undelivered < 0 || undelivered < unpicked)
            return 0;
        
        if(DP[unpicked][undelivered] != 0)
            return DP[unpicked][undelivered];
        
        long ans = 0;
        
       ans += (unpicked * ways(unpicked - 1, undelivered)) % MOD;
        ans += ((undelivered-unpicked) * ways(unpicked, undelivered - 1)) %MOD;
        
        DP[unpicked][undelivered] = ans;
        return ans;
    }
};