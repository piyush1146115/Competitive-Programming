class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int ans = 0;
        vector<int> diff;
        
        for(auto cost: costs){
            ans += cost[0];
            diff.push_back(cost[0]-cost[1]);    
        }
        
        sort(diff.rbegin(), diff.rend());
        
        int n = costs.size();
        n = n/2;
        
        for(int i = 0; i < n; i++){
            ans -= diff[i];
        }
        
        return ans;
    }
};