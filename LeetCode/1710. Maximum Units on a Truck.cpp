class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int>&a, vector<int> &b){
            return a[1]>b[1];
        });
        
        int totalUnits = 0, boxSum = 0;
        
        //[[5,10],[2,5],[4,7],[3,9]]
        //10
        //sum : 77, boxSum = 8
        for(int i = 0; i < boxTypes.size() && boxSum <= truckSize; i++){
            
            // cout << boxTypes[i][0] << " " << boxTypes[i][1] << endl;
            if(boxTypes[i][0] + boxSum <= truckSize){
                totalUnits += (boxTypes[i][0]*boxTypes[i][1]);
            }else{
                totalUnits += ((truckSize - boxSum)*(boxTypes[i][1]));
            }
            boxSum += boxTypes[i][0];
            
            //cout << boxSum << " " << totalUnits << endl;
                
        }
        
        return totalUnits;
    }
};