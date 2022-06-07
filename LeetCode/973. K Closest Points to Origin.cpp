class Solution {
public:
    struct data{
        int x, y;
        double dis;
        
        bool operator<(const data &d)const{
            return dis>d.dis;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<data> pq;
        
        for(auto point: points){
            int x = point[0];
            int y = point[1];
            double dis = sqrt(x*x+y*y);
            
            pq.push({x,y,dis});
        }
        
        
        vector<vector<int>>ans;
        
        while(k--){
            ans.push_back({pq.top().x,pq.top().y});
            pq.pop();
        }
        
        return ans;
    }
};