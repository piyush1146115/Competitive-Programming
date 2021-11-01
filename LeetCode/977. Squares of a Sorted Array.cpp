class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int p1 = -1, p2 = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                p2 = i;
                break;
            }
            p1 = i;
        }
        vector<int> ans;
        
            
        while(p1 >= 0 || p2 < nums.size()){
            if(p2 == nums.size()){
                ans.push_back(nums[p1]*nums[p1]);
                p1--;
            }
            else if(p1 == -1){
                ans.push_back(nums[p2]*nums[p2]);
                p2++;
            }
            else if(abs(nums[p1]) < nums[p2]){
                ans.push_back(nums[p1]*nums[p1]);
                p1--;
            }
            else{
                ans.push_back(nums[p2]*nums[p2]);
                p2++;
            }
        }
        return ans;
    }
};