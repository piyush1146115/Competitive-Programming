class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        
        for(auto ch: s){
            mp[ch]++;
        }
        
        int ans = 0;
        
        for(auto it: mp){
            if(it.second%2 == 0){
                ans += it.second;
            }else{
                ans += (((it.second)/2) * 2);
                if(ans % 2 == 0)
                    ans++;
            }    
        }
        
        
        
        return ans;
    }
};