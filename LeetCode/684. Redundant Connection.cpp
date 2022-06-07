class Solution {
public:
    int find(int n, vector<int>& par){
        if(par[n] == n)
            return n;
        
        return par[n] = find(par[n], par);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> par(n+1);
        
        for(int i = 1; i <= n; i++)
            par[i] = i;
        
        for(auto edge: edges){
            int u = find(edge[0], par);
            int v = find(edge[1], par);
            
            if(u != v){
                par[u] = v;
            }else{
                return {edge[0],edge[1]};
            } 
        }
        
        return {};
    }
};