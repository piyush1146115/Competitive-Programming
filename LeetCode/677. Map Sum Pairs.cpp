class MapSum {
public:
    struct TreeNode{
        TreeNode* next[26];
        int sum = 0;
    };
    TreeNode* root;
    map<string, int> mp;
    
    MapSum() {
        mp.clear();
        root = new TreeNode();
    }
    
    void insert(string key, int val) {
        TreeNode* cur = root;
        int temp = val;
        val -= mp[key];
        mp[key] = temp;
        
        int prev = 0;
        for(auto c: key){
            int ch = c - 'a';
            
            if(cur->next[ch] == NULL)
                cur->next[ch] = new TreeNode();
            
            cur->sum += val;
            prev = cur->sum;
            cur = cur->next[ch];
        }
        cur->sum += val;
    }
    
    int sum(string prefix) {
        TreeNode* cur = root;
        
        for(auto c: prefix){
            int ch = c - 'a';
            
            if(cur->next[ch] == NULL)
                cur->next[ch] = new TreeNode();
            
            cur = cur->next[ch];
        }
        
        return cur->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */