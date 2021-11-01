class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        
        int ans = stones[0];
        
        while(!pq.empty()){
            int x = pq.top();
            ans = x;
            pq.pop();
            
            if(!pq.empty()){
                int y = pq.top();
                pq.pop();
                pq.push(x-y);
            }
        }
        
        return ans;
    }
};