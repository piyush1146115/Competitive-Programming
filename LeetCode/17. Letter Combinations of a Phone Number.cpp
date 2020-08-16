class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v(11);
        
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        
        vector<string> res;
        if(digits == ""){
            return res;
        }
        
        string comb;
        calc(v, res, digits, 0, comb);
        return res;
    }
    
    void calc(vector<string>&v, vector<string>&res, string &digits, int pos, string &comb){
        if(pos == digits.size()){
            res.push_back(comb);
            return;
        }
        
        
        for(int i = 0; i < v[(digits[pos] - '0')].size(); i++){
            comb.push_back(v[(digits[pos] - '0')][i]);
            calc(v, res, digits, pos + 1, comb);
            comb.pop_back();
        }
    }
        
};
