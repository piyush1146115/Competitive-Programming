long countTriplets(vector<long> arr, long r) {
    
    map<long, long> right, left;
    
    for(auto a: arr){
        right[a]++;    
    }
    
    long ans = 0;
    
    for(int i = 0; i < arr.size(); i++){
        right[arr[i]]--;
        if(arr[i] % r == 0)
            ans += (left[arr[i]/r] * right[arr[i]*r]);    
            
        left[arr[i]]++;
    }
    
    return ans;
}