class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end()){
                int dif = i - mp[sum-k];
                maxLen = max(maxLen, dif);
            }
            
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            
        }
        
        return maxLen;
    }
};