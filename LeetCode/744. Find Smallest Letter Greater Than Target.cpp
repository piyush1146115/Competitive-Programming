class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        ans = '*';
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] > target){
                return letters[i];
            }
            if(letters[i] != target && ans == '*'){
                ans = letters[i];
            }
        }
        return ans;
    }
};