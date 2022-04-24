class Trie {
public:
     struct TrieNode{
        bool endWord = false;
        TrieNode* child[26];
    };
    
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* cur=root;
    
        for(auto c: word){
            int nxt = c - 'a';
            cout << nxt << endl;
            if(cur->child[nxt] == NULL)
                cur->child[nxt] = new TrieNode();
            cur = cur->child[nxt];   
        }
        cur->endWord = true;
    }
    
    bool search(string word) {
          TrieNode* cur=root;
    
        for(auto c: word){
            int nxt = c - 'a';
            if(cur->child[nxt] == NULL)
                return false;
            cur = cur->child[nxt];   
        }
        return cur->endWord;
    }
    
    bool startsWith(string prefix) {
         TrieNode* cur=root;
    
        for(auto c: prefix){
            int nxt = c - 'a';
            if(cur->child[nxt] == NULL)
                return false;
            cur = cur->child[nxt];   
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */