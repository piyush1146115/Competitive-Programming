class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int p1 = 0, p2 = 0;
        vector<vector<int>> ans;
        
        while(p1 < firstList.size() && p2 < secondList.size()){
            int leftMax = max(firstList[p1][0], secondList[p2][0]);
            int rightMin = min(firstList[p1][1], secondList[p2][1]);
            
            if(leftMax <= rightMin){
                ans.push_back({leftMax, rightMin});
            }
            
            if(firstList[p1][1] < secondList[p2][1]){
                p1++;
            }else{
                p2++;
            }
        }
        
        return ans;
    }
};