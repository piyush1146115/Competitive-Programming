class Solution {
public:
    map<int, int> mp;
    
    int fun(int pos, string &s){
        if(pos >= s.size())
            return 1;
        if(s[pos] == '0')
            return 0;
        if(pos == s.size() -1)
            return 1;
        
        if(mp.find(pos) != mp.end())
            return mp[pos];
        
        int ans = fun(pos+1, s);
        
        if(stoi(s.substr(pos, 2)) <= 26){
            ans += fun(pos+2, s);
        }
        
        mp[pos] = ans;
        return ans;
    }
    
    int numDecodings(string s) {
        return fun(0, s);
    }
};

/*
Enter recursion with the given string i.e. start with index 0.

For the terminating case of the recursion we check for the end of the string. If we have reached the end of the string we return 

Every time we enter recursion it's for a substring of the original string. For any recursion if the first character is 0 then terminate that path by returning 0. Thus this path won't contribute to the number of ways.

Memoization helps to reduce the complexity which would otherwise be exponential. We check the dictionary memo to see if the result for the given substring already exists.

If the result is already in memo we return the result. Otherwise the number of ways for the given string is determined by making a recursive call to the function with index + 1 for next substring string and index + 2 after checking for valid 2-digit decode. The result is also stored in memo with key as current index, for saving for future overlapping subproblems.
*/