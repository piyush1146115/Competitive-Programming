vector<int> freqQuery(vector<vector<int>> queries) {
    map<int,int> mp1, mp2;
    vector<int> response;
    
    for(auto q: queries){
        if(q[0] == 1){
            int k = mp1[q[1]];
            if(k > 0)
                mp2[k]--;
                
            mp2[k+1]++;
            mp1[q[1]]++;
        }
        if(q[0] == 2){
            int k = mp1[q[1]];
            if(k > 0){
                mp2[k]--;
                
                if(k-1 > 0)
                    mp2[k-1]++;
                
                mp1[q[1]]--;
            }
        }
        if (q[0] == 3) {
            if(mp2[q[1]] > 0){
                response.push_back(1);
            }
            else{
                response.push_back(0);
            }
        }
    }
    
    return response;
}