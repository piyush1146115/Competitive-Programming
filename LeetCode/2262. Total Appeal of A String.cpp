class Solution {
public:
    
//     What is the appeal of all substrings that end at i-th position?

// It is the same as the appeal of all substrings that end at i - 1 position, plus:
// number of substrings (ending at i-th position) that do not contain s[i] character.
// to count those substrings, we just track the previous (prev) position of s[i] character.
    
    long long appealSum(string s) {
    long long res = 0, cur = 0, prev[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        cur += i + 1 - prev[s[i] - 'a'];
        prev[s[i] - 'a'] = i + 1;
        res += cur;
    }
    return res;
        
    }
};