class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> group;
        int cnt = 1;
        
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                group.push_back(cnt);
                
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        
        group.push_back(cnt);
        
        int ans = 0;
        
        for(int i = 1; i < group.size(); i++){
            ans += min(group[i], group[i -1]);
        }
        
        return ans;
    }
};