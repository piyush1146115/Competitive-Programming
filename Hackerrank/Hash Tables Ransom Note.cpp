void checkMagazine(vector<string> magazine, vector<string> note) {
    map<string, int> word;
    
    for(auto w: magazine){
        word[w]++;
    }
    
    for(auto w: note){
        word[w]--;
        if(word[w] < 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    
    
    cout << "Yes" << endl;
}