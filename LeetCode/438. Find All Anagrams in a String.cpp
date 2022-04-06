class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        int ns = s.size();
        int np = p.size();
        
        if(np > ns)
            return ans;
        
        // unordered_map<char, int> mp, ms;
        
        vector<int> vs(26, 0), vp(26, 0);
        
        for(int i = 0; i < np; i++)
            vp[p[i] - 'a']++;
        
        
        for(int i = 0; i < ns; i++){
            
            vs[s[i] - 'a']++;
            
            if(i >= np - 1){
              if(vs == vp){
                  ans.push_back(i - np + 1);
              }  
               vs[s[i - np + 1] - 'a']--;
               // if(ms[s[i - np + 1]] == 0){
               //     ms.erase(s[i - np + 1]);
               // }
            }
        }
        
        return ans;
    }
};