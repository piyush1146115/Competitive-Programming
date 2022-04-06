class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int right = points[0][1];
        int cnt = 1;
        
        for(int i = 1; i < points.size(); i++){
            
            //cout <<i << " " << right << " " << cnt << " " << points[i][0] << endl;
            
            if(right < points[i][0]){
                cnt++;
                right = points[i][1];
                continue;
            }
            
            right = min(right, points[i][1]);
        }
        
        return cnt;
    }
};