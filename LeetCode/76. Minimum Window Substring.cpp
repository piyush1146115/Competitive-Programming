class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mps, mpt;
        
        int have = 0, need = 0;
        
        for(auto ch: t){
            if(mpt.find(ch) == mpt.end())
                need++;
            
            mpt[ch]++;
        }
        
        
        int p1 = 0, p2 = 0;
        
        int start = 0, len = INT_MAX;
        
        while(p1 < s.size()){
            if(need == have){
                if(len > (p2- p1)){
                    len = p2-p1;
                    start = p1;
                }
            
                mps[s[p1]]--;
                if(mpt[s[p1]] > mps[s[p1]])
                    have--;
                p1++;
            }
            else if(p2 < s.size()){
                mps[s[p2]]++;
                if(mps[s[p2]] == mpt[s[p2]])
                    have++;
                p2++;
            }
            else{
                break;
            }
        }
        
        if(len == INT_MAX)
            return "";
        
        return s.substr(start, len);
    }
};