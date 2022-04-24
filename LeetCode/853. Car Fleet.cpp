class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int> > vp;
        
        for(int i = 0; i < position.size(); i++){
            vp.push_back({position[i],speed[i]});
        }
        
        sort(vp.rbegin(), vp.rend());
        
        pair<int,int> prev, cur;
        int cnt = 1;
        
        for(int i = 0; i < vp.size(); i++){
            if(i == 0)
                prev = vp[i];
            else{
                double t1 = (double)(target-prev.first)/(double)prev.second;
                
                cur = vp[i];
                double t2 = (double)(target-cur.first)/(double)cur.second;
                
                if(t2 > t1){
                    cnt++;
                    prev = cur;
                }
            }
        }
        
        return cnt;
    }
};