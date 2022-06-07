class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<int> cur = intervals[0];
        int cnt = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            // cout << intervals[i][0] << " " << cur[1] <<endl;
            if(intervals[i][0]<cur[1]){
                cnt++;
                cur[1] = min(intervals[i][1], cur[1]);
            }else{
                cur = intervals[i];    
            }
        }
        
        return cnt;
    }
};