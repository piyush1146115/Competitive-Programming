class RandomizedSet {
public:
    vector<int> num;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        
        num.push_back(val);
        mp[val] = num.size() -1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
        int last = num[num.size()-1];
        mp[last] = mp[val];
        num[mp[val]] = last;
        
        num.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return num[rand()%num.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */