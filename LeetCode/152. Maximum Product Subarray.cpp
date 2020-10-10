class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int prev_min, prev_max, ans, Curr_min, Curr_max;
        
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        prev_min = prev_max = ans = nums[0];
        
        for(int i = 1; i < n; i++){
            Curr_min = min(min(prev_min * (long long)nums[i], prev_max * (long long)nums[i]) , (long long)nums[i]);
            Curr_max = max(max(prev_min * (long long)nums[i], prev_max * (long long)nums[i]) , (long long)nums[i]);
            
            ans = max(ans, Curr_max);
            
            prev_max = Curr_max;
            prev_min = Curr_min;
        }
        
        return ans;
    }
};