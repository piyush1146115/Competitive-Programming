class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 1; i < heights.size(); i++){
            if(heights[i] > heights[i - 1]){
                int dif = heights[i] - heights[i - 1];
                pq.push(dif);
                
                if(pq.size() > ladders){
                    bricks -= pq.top();
                    pq.pop();
                }
                if(bricks < 0)
                    break;
            }
            ans = i;
        }
        return ans;
    }
};