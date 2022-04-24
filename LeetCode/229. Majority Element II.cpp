class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1= 0, cnt2= 0;
        
        int candidate1 = 0, candidate2 = 0;
        
        for(auto num: nums){
            if(cnt1 > 0 && candidate1 == num){
                cnt1++;
            }
            else if(cnt2 > 0 && candidate2 == num){
                cnt2++;
            }
            else if(cnt1 == 0){
                candidate1 = num;
                cnt1++;
            }
            else if (cnt2 == 0){
                
                candidate2 = num;
                cnt2++;
            }
            else{
                
                cnt1--;
                cnt2--;   
            }
        }
        
        
        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;
        
        for(auto num: nums){
            if(num == candidate1)
                cnt1++;
            else if(num == candidate2)
                cnt2++;
        }
        
        int n = nums.size();
        
        if(cnt1 > n/3)
            res.push_back(candidate1);
        if(cnt2 > n/3)
            res.push_back(candidate2);
        
        return res;
    }
};