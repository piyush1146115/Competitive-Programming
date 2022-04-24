class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9, mid, ans = 1e9;
        
        while(lo <= hi){
            mid = (lo+hi)/2;
            int cnt = 0;
            
            for(auto pile: piles){
                cnt += (pile/mid);
                if(pile%mid != 0)
                    cnt++;
            }
            
         //  cout << mid << " " << cnt << endl;
            if(cnt <= h){
                hi = mid - 1;
                ans = min(mid, ans);
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};