class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        
        fun(1, k, n, temp, ans);
        
        return ans;
    }
    
    void fun(int pos, int k, int n, vector<int> &temp, vector<vector<int> > &ans){
        if(temp.size() > k || n < 0 || pos > 10)
            return;
        
        if(temp.size() == k){
            if(n == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(pos);
        fun(pos+1, k, n-pos, temp, ans);
        temp.pop_back();
        
        fun(pos+1, k, n, temp, ans);
    }
};