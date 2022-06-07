class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        vector<int> mp(26,1);
        
        for(auto ch: tasks){
            pq.push(mp[ch-'A']);
            mp[ch-'A'] += (n+1);
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            // cout << ans << " " << pq.top() << endl;
            
            ans++;
            ans = max(ans, pq.top());
            pq.pop();
        }
        
        return ans;
    }
};