class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int cnt[30];
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]-'a']++;
        }
        vector<int> ans;
        int len = 0;
        unordered_set<int>st;
        
        for(int i = 0; i < s.size(); i++){
            cnt[s[i]-'a']--;
            len++;
            
            if(cnt[s[i]-'a'] > 0){
                st.insert(s[i]-'a');
            }
            else{
                if(st.find(s[i]-'a') != st.end())
                    st.erase(s[i]-'a');
            }
            
            if(st.size() == 0){
                ans.push_back(len);
                len = 0;
            }
        }
        return ans;
        
    }
};