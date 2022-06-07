class Solution {
public:
    map<pair<int,int>, bool> mp;
    
    bool regExp(int i, int j, string &s, string &p){
        if(i >= s.size() && j >= p.size())
            return true;
        if(j >= p.size())
            return false;
        
        if(mp.find({i,j}) != mp.end())
            return mp[{i,j}];
        
        bool match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        
        if(j+1<p.size() && p[j+1] == '*'){
            mp[{i,j}] = (regExp(i, j+2, s, p) or //not using *
                   (match && regExp(i+1, j, s, p))); //using *        
            
            return mp[{i,j}];
        }
        
        if(match){
            mp[{i,j}] = regExp(i+1, j+1, s, p);
            return mp[{i,j}];
        }
        
        mp[{i,j}] = false;
        return mp[{i,j}];
                    
    }
    
    bool isMatch(string s, string p) {
        return regExp(0, 0, s, p);
    }
};