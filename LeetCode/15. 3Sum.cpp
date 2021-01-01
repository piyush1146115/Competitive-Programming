class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int> > ans;
        if(n < 3)
            return ans;
        
        vector<int> temp(3, 0);
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i + 1 < n; i++){
            int target = -nums[i];
            
            int st = i + 1, en = n - 1;
            int sum;
            
            while(st < en){
                sum = nums[st] + nums[en];
                
                if(sum < target)
                    st++;
                else if(sum > target)
                    en--;
                else{
                    temp[0] = nums[i];
                    temp[1] = nums[st];
                    temp[2] = nums[en];
                    
                    ans.push_back(temp);
                    
                    while(st +1 < en && nums[st] == nums[st + 1])
                        st++;
                    
                    while(st < en - 1 && nums[en] == nums[en - 1])
                        en--;
                    
                    st++;
                    en--;
                }
            }
            
            while(i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
     
        return ans;
    }
};