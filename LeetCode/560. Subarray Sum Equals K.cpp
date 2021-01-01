class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        int sum = 0 , ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};