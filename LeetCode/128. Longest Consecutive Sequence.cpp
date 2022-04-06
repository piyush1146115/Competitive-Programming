class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp, mp2;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = 1;
        }
        
        int ans = 0;
        
        for(auto it: mp){
            int cnt = 1;
           
            int n = it.first;
            
            if(mp.find(n-1) == mp.end()){
                
                while(mp.find(n+1) != mp.end()){
                    n++;
                    cnt++;
                }
                
            }
            
            
            ans = max(ans, cnt);
          //  cout << i << " " << cnt << endl;
        }
        
        return ans;
    }
};