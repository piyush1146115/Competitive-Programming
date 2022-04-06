class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            int odd = makePalindrome(s, i, i);
            int even = makePalindrome(s, i,  i + 1);
            
            int len = max(odd, even);
            
            if(len > maxLen){
                maxLen = len;
                start = i - ((len-1)/2);
            }
        }
        
        return s.substr(start, maxLen);
    }
    
    int makePalindrome(string &s, int l, int r){
            
            int len = 0;
            
            while((l < s.size() && r < s.size()) && s[l] == s[r]){
                len = r-l+1;
                
                r++;
                l--;
            }
            
            return len;
        }
};