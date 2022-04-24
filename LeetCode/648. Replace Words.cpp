class Solution {
public:
    
    struct TrieNode{
        TrieNode* next[26];
        bool endWord = false;
    };
    
    TrieNode* root;
    
    void insert(string word){
        TrieNode *cur = root;
        
        for(auto c: word){
            int ch = c - 'a';
            
            if(cur->next[ch] == NULL)
                cur->next[ch] = new TrieNode();
            
            cur = cur->next[ch];
        }
        
        cur->endWord = true;
    }
    
    string search(string word){
        TrieNode *cur = root;
        string temp;
        
//        cout << "temp: " << word << endl;
        
        for(auto c: word){
//            cout <<"c: " <<  c << endl;
            
            int ch = c-'a';
//            cout << ch << endl;
            
            if(cur->next[ch] == NULL)
                break;
            
            cur=cur->next[ch];
            temp.push_back(c);
            
            if(cur->endWord){
                return temp;
            }
        }
        
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        
        for(auto dic: dictionary){
            insert(dic);
        }
        
        string temp = "";
        string ret = "";
        
        for(int i = 0; i < sentence.size(); i++){
            
            if(sentence[i] == ' '){
                ret += search(temp);
                temp = "";
                ret += " ";
                continue;
            }
            temp += sentence[i];
        }
        
        if(temp.size() > 0)
            ret += search(temp);
        
        return ret;
    }
};