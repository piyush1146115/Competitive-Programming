class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
//         unordered_map<int,int> mp;
        
//         int ans = 0;
        
//         for(auto t: time){
//             int rem = t%60;
//             if(rem == 0){
//                 ans += mp[rem];
//             }else{
            
//                 ans += mp[60-rem];
//             }
            
//             mp[rem]++;
//         }
        
//         return ans;
        
         vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(600 - t) % 60];
            c[t % 60] += 1;
        }
        return res;
        
    }
};