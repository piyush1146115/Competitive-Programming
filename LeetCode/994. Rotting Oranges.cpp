class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<int> q;
        
        bool rotten = true;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    q.push(i);
                    q.push(j);
                    q.push(0);
                }
                if(grid[i][j] == 1){
                    rotten = false;
                }
                    
            }
        }
        
        if(rotten){
            return 0;
        }
        
        int ans = 0;
        int m = grid[0].size();
        int n = grid.size();
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            int dis = q.front();
            q.pop();
            
            int xx = x + 1;
            int yy = y;
            
            if (xx < n){
                if(grid[xx][yy] == 1){
                    ans = max(ans, dis + 1);
                    q.push(xx);
                    q.push(yy);
                    q.push(dis+1);
                    grid[xx][yy] = 2;
                }
            }
            
            xx = x - 1;
            yy = y;
            
            if (xx >= 0){
                if(grid[xx][yy] == 1){
                    ans = max(ans, dis + 1);
                    q.push(xx);
                    q.push(yy);
                    q.push(dis+1);
                    grid[xx][yy] = 2;
                }
            }
            
            xx = x;
            yy = y + 1;
            
              if (yy < m){
                if(grid[xx][yy] == 1){
                    ans = max(ans, dis + 1);
                    q.push(xx);
                    q.push(yy);
                    q.push(dis+1);
                    grid[xx][yy] = 2;
                }
            }
            
            
            xx = x;
            yy = y - 1;
             
            if (yy >= 0){
                if(grid[xx][yy] == 1){
                    ans = max(ans, dis + 1);
                    q.push(xx);
                    q.push(yy);
                    q.push(dis+1);
                    grid[xx][yy] = 2;
                }
            }
        }
        
         for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    ans = -1;
                }
                    
            }
        }
        
        return ans;
    }
};