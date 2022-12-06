string twoStrings(string s1, string s2) {
    unordered_map<char, int> mp;
    
    for(auto ch: s1){
        mp[ch]++;
    }
    
    for(auto ch: s2){
        if(mp.find(ch) != mp.end()){
           
            return "YES";
        }
    }
    
    return "NO";
}