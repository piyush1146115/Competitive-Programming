class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
//         vector<int> road(1001, 0);
        
//         for(auto trip: trips){
//             road[trip[1]] += trip[0];
//             road[trip[2]] -= trip[0];
//         }
        
//         int sum = 0;
        
//         for(int i = 0; i <= 1000; i++){
//             sum += road[i];
//             if(sum > capacity)
//                 return false;
//         }
        
//         return true;
        
         map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0];
        
        for (auto &v : m)
            if ((capacity -= v.second) < 0)
                return false;
        return true;
    }
};