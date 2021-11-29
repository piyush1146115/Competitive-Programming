class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++){
            ans += palindrome(s, i, i + 1);
            ans += palindrome(s, i, i);
        }
        
        return ans;
    }
    
    int palindrome(string &s, int i, int j){
        int cnt = 0;
        
        while(i >= 0 && j < s.size() && s[i] == s[j] ){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
};