class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnt = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            cnt = max(cnt, nums[i]);
            if(cnt == 0)
                return false;
            cnt--;
        }
        return true;
    }
};