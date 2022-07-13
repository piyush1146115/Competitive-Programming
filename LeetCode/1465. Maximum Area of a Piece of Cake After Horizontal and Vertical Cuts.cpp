
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long int maxHr = 0, maxVr = 0;
        
        int prev = 0;
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        for(auto cut: horizontalCuts){
            long long dif = cut - prev;
            maxHr = max(dif, maxHr);
            prev = cut;
        }
        
        prev = 0;
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        
        for(auto cut: verticalCuts){
            long long dif = cut - prev;
            maxVr = max(maxVr, dif);
            prev = cut;
        }
        
        long long area = (maxHr*maxVr) % MOD;
        
        return (int)area;
    }
};