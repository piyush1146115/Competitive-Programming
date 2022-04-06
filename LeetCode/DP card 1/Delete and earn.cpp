class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> cnt;
        
        for(auto num : nums){
            cnt[num] += num;
        }
        
        int take = 0, skip = 0;
        
        for(int i = 1; i <= 10000; i++){
            if(cnt.find(i) != cnt.end()){
                int mx = max(take, skip);
                
                if(cnt.find(i-1) != cnt.end()){
                    take = cnt[i] + skip;
                }
                else{
                    take = cnt[i] + mx;
                }
                skip = mx;
            }
        }
        
        return max(take, skip);
    }
};