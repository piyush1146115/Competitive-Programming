int activityNotifications(vector<int> expenditure, int d) {
    vector<int> freq(201, 0);
    int n = expenditure.size();
    
    for(int i = 0; i < min(d,n) ; i++){
        freq[expenditure[i]]++;
    }
    
    int cnt = 0;
    
    for(int i = d; i < n; i++){
        
        int med1 = 0, sum = 0;
        for(int j = 0; j <= 200; j++){
            sum += freq[j];
            if(sum >= (d+1)/2){
                med1 =j;
                break;
            }
        }
        
        int med2;
        sum = 0;
        for(int j = 200; j >= 0; j--){
            sum += freq[j];
            if(sum >= (d+1)/2){
                med2 = j;
                break;
            }
        }
        
        if (med1+med2 <= expenditure[i]) {
            cnt++;
        }
        
        freq[expenditure[i-d]]--;
        freq[expenditure[i]]++;
    }
    
    return cnt;
}