class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<int>tmp;
        
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j >= 0; j--){
                tmp.push_back(matrix[j][i]);        
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = tmp[cnt++];
            }
        }
    }
};