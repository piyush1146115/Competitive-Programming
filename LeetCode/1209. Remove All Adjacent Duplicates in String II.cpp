class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int> > st;
        
        for(auto ch: s){
            if(st.empty()){
                st.push({ch,1});
            }
            else{
                if(st.top().first == ch){
                    st.push({ch, st.top().second +1});
                }
                else{
                    
                    st.push({ch,1});
                }
                
                if(st.top().second == k){
                    int K = k;
                    
                    while(K--){
                        st.pop();
                    }
                }
            }
        }
        
        string ans;
        
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};