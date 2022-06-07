class Solution {
public:
    int dir[8][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int row, col;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int>> dis(row, vector<int>(col,-1));
        
        queue<pair<int,int> > q;
        
        if(grid[0][0] == 1)
            return -1;
        
        q.push({0,0});
        dis[0][0] = 1;
        
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++){
                int xx = cur.first + dir[i][0];
                int yy = cur.second + dir[i][1];
                
                if(xx >= 0 && yy >= 0 && xx < row && yy < col && dis[xx][yy] == -1 && grid[xx][yy] == 0){
                    dis[xx][yy] = dis[cur.first][cur.second] + 1;
                    q.push({xx,yy});
                }
            }
        }
        
        return dis[row-1][col-1];
    }
};