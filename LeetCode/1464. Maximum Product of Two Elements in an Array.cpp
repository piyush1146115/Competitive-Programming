class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = nums[0];
        int y = -100000;
        
        for(int i = 1; i < nums.size(); i++){
            if(x < nums[i]){
                y = x;
                x = nums[i];
            }
            else if(y < nums[i]){
                y = nums[i];
            }
        }
        
        return (x-1)*(y-1);
    }
};