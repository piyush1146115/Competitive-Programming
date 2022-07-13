class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int subArrayStart = -1, firstNeg = -1, neg = 0, maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == 0){
                neg = 0;
                subArrayStart = i;
                firstNeg = -1;
               
            }else{
            
                if(nums[i] < 0){
                    neg++;
                }
                if(neg == 1 && firstNeg == -1){
                    firstNeg = i;
                }

                if(neg % 2 == 0){
                    maxLen = max(maxLen, i - subArrayStart);
                }
                else{
                    maxLen = max(maxLen, i - firstNeg);
                }
            }
        }
        
        return maxLen;
    }
};