class Solution {
public:
    bool checkValidString(string s) {
        
        int starCount = 0;
        stack<char> st;
        
        for(auto ch: s){
            if(ch == ')'){
                if(!st.empty()){
                    st.pop();
                    continue;
                }
                if(starCount > 0){
                    starCount--;
                    continue;
                }
                return false;
            }
            else if(ch == '('){
                st.push('(');
            }
            else{
                starCount++;
                if(!st.empty()){
                    starCount++;
                    st.pop();
                }
            }
        }
        
        if(st.size() > 0)
            return false;
        
        return true;

    
    int lo = 0, hi = 0;
        
       for (auto c: s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = max(lo, 0);
       }
       return lo == 0;
    }
};