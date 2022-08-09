class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long,long>>> graph(n + 1);
        
        for(auto r: roads){
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }
        
        priority_queue<pair<long, long>, vector<pair<long,long>>, greater<pair<long,long>> >pq;
        
        long long MOD = 1e9+7;
        
        vector<long long> dis(n+1, LONG_LONG_MAX), ways(n+1, 0);
        
        dis[0] = 0;
        ways[0] = 1;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            pair<long long, long long> tp = pq.top();
            pq.pop();
            
            int node = tp.second;
            long long wt = tp.first;
            
            if(wt > dis[node])
                continue;
            
            for(auto g: graph[node]){
                long long child = g.first;
                long long childWt = g.second;
                
                if(wt+childWt == dis[child]){
                    ways[child] = (ways[child] + ways[node]) % MOD;
                }
                if(wt+childWt < dis[child]){
                    ways[child] = ways[node] % MOD;
                    dis[child] = wt+childWt;
                    pq.push({dis[child], child});
                }
            }
        }
        
        return ways[n-1]%MOD;
    }
};