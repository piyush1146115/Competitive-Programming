class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        long long sum = 0;
        int mx = 0;
        for(int i = 0; i < milestones.size(); i++){
           sum += milestones[i];
           mx = max(mx, milestones[i]);
        }
        
        return min(sum, 2*(sum-mx) +1);
    }
};