class Solution {
public:
    
    void dfs(int pos, vector<vector<int>> &gr, vector<int> &vis){
        
        vis[pos] = 1;
        
        
        for(auto p: gr[pos]){
            if(vis[p] == 0){
                dfs(p, gr, vis);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        vector<int> vis(n, 0);
        
        for(auto edge: edges){
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(i, gr, vis);
                ans++;
            }
        }
        
        return ans;
        
    }
};