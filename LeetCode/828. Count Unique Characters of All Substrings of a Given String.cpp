class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> vec[27];
        
        for(int i = 0; i < s.size(); i++){
            vec[s[i] - 'A'].push_back(i);
        }
        
        int ans = 0, n = s.size();
        
        for(int i  = 0; i < 26; i++){
            if(vec[i].size() > 0){
                for(int j = 0; j < vec[i].size(); j++){
                    int left, right;
                    
                    if(j == 0){
                        left = vec[i][j] + 1;
                    }
                    else{
                        left = vec[i][j] - vec[i][j - 1];
                    }
                    
                    if(j == vec[i].size() - 1){
                        right = n - vec[i][j];
                    }
                    else{
                        right = vec[i][j + 1] - vec[i][j];
                    }
                    
                    ans += (left*right);
                }
            }
        }
        
        return ans;
    }
};