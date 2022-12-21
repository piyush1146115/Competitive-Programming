class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mpst, mpts;

        for(int i = 0; i < s.size(); i++){
            if((mpst.find(s[i]) != mpst.end() && mpst[s[i]] != t[i]) ||
                (mpts.find(t[i]) != mpts.end() && mpts[t[i]] != s[i])){
                return false;
            }

            mpst[s[i]] = t[i];
            mpts[t[i]] = s[i];
        }

        return true;
    }
};