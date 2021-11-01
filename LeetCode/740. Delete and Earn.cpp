class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int cnt[10005];
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        
        int prev = -1, m, taken = 0, skip = 0;
        
        for(int i = 1; i <= 10000; i++){
            if(cnt[i] > 0){
                m = max(taken, skip);
                
                if(prev != (i-1)){
                    taken = cnt[i]*i + m;
                }
                else{
                    taken = cnt[i]*i + skip;
                }
                skip = m;
                prev = i;
            }
        }
        return max(taken, skip);
    }
};