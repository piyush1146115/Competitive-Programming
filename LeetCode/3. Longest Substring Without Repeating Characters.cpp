class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        
        map<char, int> mp;
        int ans = 0, p1 = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(mp.find(s[i]) != mp.end()){
                p1 = max(p1, mp[s[i]] + 1);
                
            }
            
            
            ans = max((i - p1 + 1), ans);
            mp[s[i]] = i;
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        
        int mp[128];
        memset(mp, -1, sizeof(mp));
        int ans = 0, p1 = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(mp[s[i]] != -1){
                p1 = max(p1, mp[s[i]] + 1);
                
            }
            
            
            ans = max((i - p1 + 1), ans);
            mp[s[i]] = i;
        }
        return ans;
    }
};