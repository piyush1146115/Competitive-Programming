class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > ans;
        vector<int> temp;
        
        subset(0, nums, temp, ans);
        
        return ans;
    }
    
    void subset(int pos, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        
        if(pos == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[pos]);
        subset(pos+1, nums, temp, ans);
        temp.pop_back();
        
        while(pos + 1 < nums.size() && nums[pos] == nums[pos+1]){
            pos++;
        }
        subset(pos+1,nums,temp, ans);
    }
};