void minimumBribes(vector<int> q) {
    int count = 0;
    int n = q.size() - 1;
    
    for(int i = n; i >= 0; i--){
        if((i + 1) != q[i]){
            if((i - 1) >= 0 && q[i-1] == (i+1)){
                swap(q[i], q[i-1]);
                count++;
            }
            else if(i - 2 >= 0  && q[i-2] ==(i+1)){
                swap(q[i-1], q[i-2]);
                swap(q[i], q[i-1]);
                count += 2;
            }
            else{
                cout << "Too chaotic" << endl;
                return;
            }
        }
    }
    
    cout << count << endl;
}