class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < score.size(); i++){
            pq.push(score[i]);    
        }
        
        map<int, int> mp;
        int cnt = 0;
        
        while(!pq.empty()){
            int tmp = pq.top();
            mp[tmp] = ++cnt;
            pq.pop();
        }
        
        vector<string> ans;
        for(int i = 0; i < score.size(); i++){
            if(mp[score[i]] == 1){
                ans.push_back("Gold Medal");
            }
            else if(mp[score[i]] == 2){
                ans.push_back("Silver Medal");
            }
            else if(mp[score[i]] == 3){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(mp[score[i]]));
            }
        }
        
        return ans;
    }
};