class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        map<int, bool> invalidCol;

        string prev = strs[0];
        int ans = 0;

        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                if(j < strs[i-1].size() && strs[i][j] < strs[i-1][j] && (invalidCol.find(j) == invalidCol.end())){
                    invalidCol[j] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};