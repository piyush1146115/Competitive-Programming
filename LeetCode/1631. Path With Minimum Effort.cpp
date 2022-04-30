class Solution {
public:
    int row, col;
    
    
    int dir[4][2] = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
    
    
    
    bool isValid(int x, int y){
        if(x < 0 || y < 0 || x >= row || y >= col)
            return false;
        
        return true;
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        
        priority_queue<Cell> pq;
        
        vector<vector<bool> > vis(row, vector<bool>(col, false));
        vector<vector<int> > difMatrix(row, vector<int>(col, INT_MAX));
        
        difMatrix[0][0] = 0;
        pq.push({0,0, difMatrix[0][0]});
        
        while(!pq.empty()){
            Cell cur = pq.top();
            pq.pop();
            
            vis[cur.x][cur.y] = true;
            
            if(cur.x == row -1 && cur.y == col -1)
                return difMatrix[cur.x][cur.y];
            
            
            for(int i = 0; i < 4; i++){
                int xx = cur.x + dir[i][0];
                int yy = cur.y + dir[i][1];
                
                if(isValid(xx,yy) && !vis[xx][yy]){
                    int curDif = (abs(heights[xx][yy] - heights[cur.x][cur.y]));
                    
                    int maxDif = max(curDif, difMatrix[cur.x][cur.y]);
                    
                    if(maxDif < difMatrix[xx][yy]){
                        difMatrix[xx][yy] = maxDif;
                        pq.push({xx,yy, difMatrix[xx][yy]});
                    }
                }
            }
        }
        
        return difMatrix[row-1][col-1];
    }
    
class Cell{
public:
  int x, y, dif;
    
 Cell(int x, int y, int dif) {
        this->x = x;
        this->y = y;
        this->dif = dif;
}
    
bool operator<(const Cell &b) const{
    return b.dif<dif;
}
    
};
    
};

