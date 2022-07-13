class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        
        for(auto ch: s){
            freq[ch-'a']++;
        }
        
        stack<char> st;
        vector<int> taken(26, 0);
        
        for(auto ch: s){
                
            if(taken[ch - 'a'] == 0){
                while(!st.empty() && ch < st.top() && freq[st.top() - 'a'] > 0){
                    taken[st.top() - 'a'] = 0;
                    st.pop();
                }
                
                st.push(ch);
                taken[ch-'a'] = 1;
            }
            freq[ch-'a']--;
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};