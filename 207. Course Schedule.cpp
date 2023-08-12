class Solution {
public:

    bool dfs(int cur, vector<int>&vis, unordered_map<int, vector<int>>& dep){
        vis[cur] = 1;

        for(auto n: dep[cur]){
            if(vis[n] == 1){
                return false;
            }
            if (vis[n] == 0){
                bool ret = dfs(n, vis, dep);
                if (ret == false) {
                    return false;
                }
            }

        }

        vis[cur] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> > dep;
        for(auto pre: prerequisites){
            dep[pre[0]].push_back(pre[1]);
        }

        vector<int> vis(numCourses+1, 0);

        for(int i = 1; i <= numCourses; i++){
            if(vis[i] == 0){
                bool ret = dfs(i, vis, dep);
                if(ret == false)
                    return false;
            }
        }

        return true;
    }
};