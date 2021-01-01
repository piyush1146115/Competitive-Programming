class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        int sz = arr.size();
        int lo = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        
        if(lo == 0 || lo == sz){
            if(lo == 0){
                for(int i = 0; i < k; i++){
                    ans.push_back(arr[i]);
                }
            }
            else{
                lo = sz - k - 1;
                while(lo < sz){
                    ans.push_back(arr[lo]);
                }
            }
            
            return ans;
        }
        
        int p1 = lo - 1, p2 = lo, cnt = 0;
        
        while(p1 >= 0 && p2 < sz && cnt < k){
            if(abs(arr[p1] - x) <= abs(arr[p2] - x)){
                p1--;
                cnt++;
            }
            else{
                p2++;
                cnt++;
            }
        }
        
        if(cnt < k){
            if(p1 >= 0){
                p1 -= (k - cnt);
            }
            else{
                p2 += (k - cnt);
            }
        }
        
        for(int i = p1 + 1; i < p2; i++){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};