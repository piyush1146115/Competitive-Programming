class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, left = -1, right = -1;
        
        for(auto vec: intervals){
            if(vec[0] > left && vec[1] > right){
                ans++;
                left = vec[0];
            }
            right = max(right, vec[1]);
        }
        return ans;
    }
};