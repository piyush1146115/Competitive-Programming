class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int left = 0, right = 1, n = nums.size(), ans = 0;
        int dif = nums[1] - nums[0];
        
        while(right < n){
            if((nums[right] - nums[right-1]) == dif){
                right++;
            }
            else{
                if(right - left >= 3){
                    int len = right-left;
                    
                    ans += (((len-1)*(len-2))/2);
                }
                
                left = right-1;
                dif = nums[right]-nums[left];
            }
        }
        
        int len = right-left;
        
        
        if(right - left >= 3)
            ans += (((len-1)*(len-2))/2);
        
        return ans;
    }
};