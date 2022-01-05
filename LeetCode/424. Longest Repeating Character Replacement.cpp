class Solution {
public:
    int characterReplacement(string s, int k) {
        int st = 0, ans = 0, mx = 0;
        vector<int> freq(28, 0);
        
        for(int en = 0; en < s.size(); en++){
            
            mx = max(mx, ++freq[s[en]- 'A']);
            
            while((en-st+1 - mx) > k){
                --freq[s[st]-'A'];
                st++;
            }
            ans = max(ans, en-st+1);
        }
        
        return ans;
    }
};