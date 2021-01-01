class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    ans += 4;
                    
                    if(i - 1 >= 0){
                        if(grid[i - 1][j] == 1)
                            ans--;
                    }
                    
                    if(i + 1 < grid.size()){
                        if(grid[i + 1][j] == 1)
                            ans--;
                    }
                    
                    if(j + 1 < grid[i].size()){
                       if(grid[i][j + 1] == 1)
                            ans--;
                    }
                     
                    if(j - 1  >= 0){
                       if(grid[i][j - 1] == 1)
                            ans--;
                    }
                }
            }
        }
        return ans;
    }
};