class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> mp;
        
        for(int i = 0; i < J.size(); i++){
            mp[J[i]] = 1;
        }
        int ans = 0;
        for(int i = 0; i < S.size(); i++){
            if(mp.find(S[i]) != mp.end())
                ans++;
        }
        
        return ans;
    }
};