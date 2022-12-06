class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int mx = -1;
        
        for(int i = n -1; i >= 0; i--){
            int temp = arr[i];
            arr[i] = mx;
            mx = max(mx, temp);    
        }

        return arr;
    }
};