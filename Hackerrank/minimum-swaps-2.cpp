int minimumSwaps(vector<int> arr) {
    unordered_map<int, int> mp;
    
    int n = arr.size();
    for(int i = 0; i < n; i++){
        mp[arr[i]] = i;
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != (i+1)){
            int pos = mp[i+1];
            
            swap(arr[i], arr[pos]);
            mp[i+1] = i;
            mp[arr[pos]] = pos;
            cnt++;
        }
    }
    
    return cnt;

}