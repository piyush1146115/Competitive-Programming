class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        int cnt = 0;
        
        vector<int> left(n, 0), right(n, 0);
        
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i - 1])
                cnt++;
            else
                cnt = 0;
            
            left[i] = cnt;
        }
        
        cnt = 0;
        
       
        
        for(int i = n - 2; i >= 0; i--){
            if(security[i] <= security[i+1])
                cnt++;
            else
                cnt = 0;
            
            
            right[i] = cnt;
        }
        
        
        vector<int> ans;
        for(int i = 0;i < n; i++){
            if(left[i] >= time && right[i] >= time){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};