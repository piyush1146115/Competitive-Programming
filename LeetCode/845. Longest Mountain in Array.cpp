class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int p1, p2, p = 1, n = arr.size(), ans = 0;
        
        while(p < n - 1){
            if(arr[p] > arr[p-1] && arr[p] > arr[p+1]){
                p1 = p;
                p2 = p;
                
                while(p1 > 0 && (arr[p1] > arr[p1 - 1])){
                    p1--;
                }
                
                while(p2 < n - 1 && arr[p2] > arr[p2 + 1]){
                    p2++;
                }
                
                ans = max(ans, p2-p1+1);
                p = p2;
                
            }else{
                p++;
            }
        }
        
        return ans;
    }
};