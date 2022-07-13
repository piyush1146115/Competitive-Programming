class Trie
{
    struct Node{
        bool isWord = false;
        vector<Node *> children{vector<Node *>(26, NULL)};
    } *root, *curr;
    
    void dfsWithPrefix(Node *curr, string &word, vector<string> &result){
        if(result.size() == 3)
            return;
        
        if(curr->isWord){
            result.push_back(word);
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            if (curr->children[c-'a']){
                word += c;
                dfsWithPrefix(curr->children[c-'a'], word, result);
                word.pop_back();
            }
        }
    }
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string &s) {
        curr = root;
        
        for(char &c: s) {
            if (!curr->children[c-'a']){
                curr->children[c-'a'] = new Node();
            }
            
            curr = curr->children[c-'a'];
        }
        
        curr->isWord = true;
    }
    
    vector<string> getWordsStartingWith(string &prefix){
        curr = root;
        vector<string> result;
        
        for(char &c: prefix) {
            if(!curr->children[c-'a']){
                return result;
            }
            
            curr = curr->children[c-'a'];
        }
        dfsWithPrefix(curr, prefix, result);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        
        vector<vector<string>> result;
        
        for(string &w: products)
            trie.insert(w);
        
        string prefix;
        
        for(char &c: searchWord) {
            prefix += c;
            result.push_back(trie.getWordsStartingWith(prefix));
        }
        return result;
    }
};