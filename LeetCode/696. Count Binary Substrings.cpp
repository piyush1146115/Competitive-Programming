class Solution {
public:
    int countBinarySubstrings(string s) {
        // vector<int> group;
        int cur = 1, prev = 0, ans = 0;
        
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                // group.push_back(cnt);
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else{
                cur++;
            }
        }
        ans += min(prev, cur);
        
        return ans;
        
//         group.push_back(cnt);
        
//         int ans = 0;
        
//         for(int i = 1; i < group.size(); i++){
//             ans += min(group[i], group[i -1]);
//         }
        
//         return ans;
    }
};