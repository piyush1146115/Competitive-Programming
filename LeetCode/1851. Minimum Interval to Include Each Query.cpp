class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        
        set<int> st;
        for(auto query: queries){
            st.insert(query);
        }
        
        map<int, int> mq;
        
        int indx = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto q: st){
            while(indx < intervals.size() && intervals[indx][0] <= q){
                pq.push({intervals[indx][1]-intervals[indx][0]+1, intervals[indx][1]});
                indx++;
            }
            
            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }
            
            mq[q] = (pq.empty())?-1:pq.top().first;
        }
        
        vector<int> ans;
        
        for(auto query: queries){
            ans.push_back(mq[query]);
        }
        
        return ans;
    }
};