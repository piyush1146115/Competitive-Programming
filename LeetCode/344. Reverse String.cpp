class Solution {
public:
    void reverseString(vector<char>& s) {
        int p1 = 0, p2 = s.size() - 1;
        
        while(p1 < p2){
            swap(s[p1], s[p2]);
            p1++;
            p2--;
        }
    }
};