class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > ans;
        if(nums.size() == 0)
            return ans;
        
        vector<int> taken(nums.size() + 2);
        vector<int> v;
        generate(ans, taken, nums, v);
        
        return ans;
    }
    
    void generate(vector< vector<int> > &ans, vector<int> &taken, vector <int> &nums, vector <int> &v)
    {
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i = 0; i < (int)nums.size(); i++){
            if(taken[i] == 0){
                taken[i] = 1;
                v.push_back(nums[i]);
                generate(ans, taken, nums, v);
                v.pop_back();
                taken[i] = 0;
            }
        }
    }
};
