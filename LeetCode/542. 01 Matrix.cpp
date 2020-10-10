class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n == 0)
            return matrix;
        int m = matrix[0].size();
        
        vector<vector<int> > dist(n, vector<int>(m, 100000));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                }
                else{
                    if(i - 1 >= 0)
                        dist[i][j] = min(dist[i][j], 1 + dist[i - 1][j]);
                    if(j - 1 >= 0)
                        dist[i][j] = min(dist[i][j], 1 + dist[i][j - 1]);
                }
            }
        }
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i + 1 < n)
                    dist[i][j] = min(dist[i][j], 1 + dist[i + 1][j]);
                if(j + 1 < m)
                    dist[i][j] = min(dist[i][j], 1 + dist[i][j + 1]);
            }
        }
        
        return dist;
    }
};