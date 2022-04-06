class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<vector<int> > gr(50002);
        
        for(int i = 0; i < pid.size(); i++){
            gr[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        queue<int>q;
        unordered_map<int, int> mp;
        
        q.push(kill);
        mp[kill] = 1;
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            
            ans.push_back(k);
            
            for(int i = 0; i < gr[k].size(); i++){
                if(mp.find(gr[k][i]) == mp.end()){
                    q.push(gr[k][i]);
                    mp[gr[k][i]] = 1;
                }        
            }
        }
        
        return ans;
        
    }
};