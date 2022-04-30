class Solution {
public:
  
    vector<int> gr[42];
    bool vis[42];
    vector<double> weights[42];
    int des;
    double ret;
    
    void dfs(int node, double mul){
        
       // cout << node << " " << mul << endl;
        
        if(node == des){
            vis[des] = true;
            ret = mul;
            return;
        }
        
        vis[node] = true;
        for(int i = 0; i < gr[node].size(); i++){
            if(vis[gr[node][i]] == false){
                dfs(gr[node][i], mul*weights[node][i]);
            }
        }
    }
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string,int> mp;
        int cnt = 0;
        
        for(int i = 0; i < equations.size(); i++){
            if(mp.find(equations[i][0]) == mp.end()){
                mp[equations[i][0]] = cnt++;
            }
            if(mp.find(equations[i][1]) == mp.end()){
                mp[equations[i][1]] = cnt++;
            }
            
            gr[mp[equations[i][0]]].push_back(mp[equations[i][1]]);
            weights[mp[equations[i][0]]].push_back(values[i]);
            gr[mp[equations[i][1]]].push_back(mp[equations[i][0]]);
            weights[mp[equations[i][1]]].push_back(1.0/values[i]);
        }
        
        
        vector<double> ans;
        for(auto query: queries){
            string q1 = query[0];
            string q2 = query[1];
            
          //  cout << q1 << " " << mp[q1] << " " << q2 << " " << mp[q2] << endl;
            
            if((mp.find(q1) == mp.end()) || (mp.find(q2) == mp.end())){
                ans.push_back(-1.0);
            }
            else{
                memset(vis, 0, sizeof(vis));
                des = mp[q2];
                
                ret = -1.0;
                
                dfs(mp[q1], 1.0);
                
                if(vis[mp[q2]]){
                    ans.push_back(ret);
                }
                else{
                    ans.push_back(-1.0);
                }
            }
        }
        return ans;
    }
};