class Solution {
public:
    int tribonacci(int n) {
        
        vector<int> Tri(n+5);
        
        Tri[0] = 0;
        Tri[1] = 1;
        Tri[2] = 1;
        
        for(int i = 3; i <= n; i++){
            Tri[i] = Tri[i -1] + Tri[i-2] + Tri[i-3];
        }
        
        return Tri[n];
    }
};