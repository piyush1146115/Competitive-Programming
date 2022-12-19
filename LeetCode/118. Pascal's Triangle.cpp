class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i = 1; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j <= i; j++){
                int sum = 0;
                if(j - 1 >= 0)
                    sum += ans[i-1][j - 1];
                if(j < i)
                    sum += ans[i-1][j];
                
                temp.push_back(sum);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};