class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "AEIOUaeiou";
        int n = (int)s.size();
        
        int p1 = 0, p2 = n - 1;
        
        while(p1 < p2){
            
            while((p1 < p2) && (vowel.find(s[p1]) > 9 )){
                p1++;
            }
            
            while((p1 < p2) && (vowel.find(s[p2]) > 9)){
                p2--;
            }
            
            if(p1 < p2){
                swap(s[p1], s[p2]);
            }
            p1++;
            p2--;
        }
        
        return s;
    }
};