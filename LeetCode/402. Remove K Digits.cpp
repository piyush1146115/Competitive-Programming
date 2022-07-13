class Solution {
public:
    string removeKdigits(string num, int k) {
        
        //Corner case: s = "9", k = 1, ans = "0"
        
        stack<char> st;
        
        for(auto ch: num){
            while(!st.empty() && st.top()>ch && k > 0){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        
        string ret;
        while(!st.empty()){
            if(k > 0){
                k--;
                st.pop();
                continue;
            }
            ret.push_back(st.top());
            st.pop();
        }
        
        reverse(ret.begin(), ret.end());
        
        int nonZeroIndex = -1;
        
        for(int i = 0; i < ret.size(); i++){
            if(ret[i] != '0'){
                nonZeroIndex = i;
                break;
            }        
        }
        
        if(nonZeroIndex == -1){
            return "0";
        }
        
        return ret.substr(nonZeroIndex);
        
    }
};