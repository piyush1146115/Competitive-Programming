class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string st;
        if(n == 0)
            return res;
        
        generate(0, n, res, st);
        
        return res;
    }
    
    void generate(int sum, int n, vector<string> &res, string &st)
    {
        if(sum == 0 && (st.size())/2 == n){
            res.push_back(st);
            return;
        }
        
        if((st.size())/2 >= n)
            return;
        
        if(sum >= 0 && sum < n){
            st.push_back('(');
            generate(sum + 1, n, res, st);
            st.pop_back();
        }
        
        if(sum > 0){
            st.push_back(')');
            generate(sum - 1, n, res, st);
            st.pop_back();
        }
    }
};
