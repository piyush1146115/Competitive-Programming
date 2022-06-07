class Solution {
public:
    struct node{
      int x, y, cost;
        
        bool operator <(const node&a)const{
            return cost>a.cost;
        }
    };
    
    int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dis(row, vector<int>(col,INT_MAX));
        // vector<vector<int>> vis(row, vector<int>(col,0);
                                
        priority_queue<node> pq;
        pq.push({0,0,grid[0][0]});
        
                                
        while(!pq.empty()){
            node tp = pq.top();
            pq.pop();
            
            // vis[tp.x][tp.y] = 1;
            dis[tp.x][tp.y] = min(dis[tp.x][tp.y],tp.cost);
            
            for(int i = 0; i < 4; i++){
                int xx = tp.x+dir[i][0];
                int yy = tp.y+dir[i][1];
                
                if(xx >= 0 && yy >= 0 && xx < row && yy < col && max(tp.cost,grid[xx][yy]) < dis[xx][yy]){
                    pq.push({xx,yy,max(tp.cost,grid[xx][yy])});
                }
            }
        }
                                
        return dis[row-1][col-1];
        
    }
};