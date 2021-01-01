class Node {
    public:
    bool endmark;
    Node *next[27];
    
    Node(){
        endmark = false;
        
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root; 
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        
        for(int i = 0; i < word.size(); i++){
            int id = word[i] - 'a';
            
            if(curr -> next[id] != NULL)
                curr = curr -> next[id];
            else{
                curr -> next[id] = new Node();
                curr = curr -> next[id];
                }
        }
        curr -> endmark = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        
        for(int i = 0; i < word.size(); i++){
            int id = word[i] - 'a';
            
            if(curr -> next[id] != NULL)
                curr = curr -> next[id];
            else
                return false;
        }
        return curr -> endmark;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        
        for(int i = 0; i < prefix.size(); i++){
            int id = prefix[i] - 'a';
            
            if(curr -> next[id] != NULL)
                curr = curr -> next[id];
            else
                return false;
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
