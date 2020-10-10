class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        int r = (1 << n);
        vector<vector<int> > ans;
       
        for(int i = 0; i < r; i++){
             vector<int> temp;
            for(int j = 0; j < n; j++){
                if((1 << j) & i){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
