class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> modifiedArray(length, 0);
        
        for(auto update: updates){
            modifiedArray[update[0]] += update[2];
            if(update[1] + 1 < length)
                modifiedArray[update[1] +1] += (-update[2]);
        }
        
        int sum = 0;
        
        for(int i = 0; i < length; i++){
            cout << modifiedArray[i] << " ";
            sum += modifiedArray[i];
            
            modifiedArray[i] = sum;
        }
        
        return modifiedArray;
    }
};