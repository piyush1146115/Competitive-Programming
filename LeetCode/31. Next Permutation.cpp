class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int left = -1, right = n -1;
        
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                left = i -1;
                break;
            }
        }
        
        if(left == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
            
        
        for(int i = left + 1; i < n; i++){
            if(nums[i] > nums[left]){
                right = i;
            }
            else{
                break;
            }
        }
        swap(nums[left], nums[right]);
        
        reverse(nums.begin()+left+1, nums.end());
        
        
    }
};