class Solution {
public:
    int maxArea(vector<int>& height) {
        
        long long int ans = 0;
        
        long long int p1 = 0, p2 = (int)height.size() - 1;
        
        while(p1 <= p2){
            ans = max(ans, (p2-p1)*(min(height[p1], height[p2])));
            if(height[p1] < height[p2])
                p1++;
            else
                p2--;
        }
        return ans;
    }
};
