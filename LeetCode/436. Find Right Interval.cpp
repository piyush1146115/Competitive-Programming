class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starting;
        
        for(int i = 0; i < intervals.size(); i++){
            starting[intervals[i][0]] = i;
        }
        
        
        vector<int> ans;
        
        for(int i = 0; i < intervals.size(); i++){
           if(starting.lower_bound(intervals[i][1]) != starting.end()){
               ans.push_back(starting.lower_bound(intervals[i][1])->second);
           }
            else{
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};