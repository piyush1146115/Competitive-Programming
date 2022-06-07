class Solution {
public:
    int parseString(string &word){
        int ret = 0;
        
        for(auto ch: word){
            int pos = ch - 'a';
            ret = ret | (1 << pos);
        }
        
        return ret;
    }
    
    int maxProduct(vector<string>& words) {
        
        vector<pair<int,int>> vp;
        
        for(auto word: words){
            int parsed = parseString(word);
            vp.push_back({parsed,word.size()});
        }
        
        int ans = 0;
        for(int i = 0; i < vp.size(); i++){
            for(int j = i + 1; j < vp.size(); j++){
                if((vp[i].first & vp[j].first) == 0){
                    ans = max(ans, vp[i].second*vp[j].second);
                }
            }
        }
        
        return ans;
    }
};