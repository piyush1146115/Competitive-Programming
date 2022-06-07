class Solution {
public:
    bool canTransform(string start, string end) {
        int stIndex = 0, enIndex = 0;
        map<char, int> mp;
        
        for(auto ch: start){
            mp[ch]++;
        }
        
        for(auto ch: end){
            mp[ch]--;
        }
        
        if(mp['X'] != 0 || mp['L'] != 0 || mp['R'] != 0)
            return false;
        
        
        while(stIndex < start.size()  && enIndex < end.size()){
            while(stIndex < start.size() && start[stIndex] == 'X'){
                stIndex++;
            }
            while(enIndex < end.size() && end[enIndex] == 'X'){
                enIndex++;
            }
            
            if(stIndex < start.size() && start[stIndex] == 'L'){
               if(enIndex >= end.size() || end[enIndex] == 'R' || enIndex > stIndex){
                   return false;
               }
                enIndex++;
            }
            else if(stIndex < start.size() && start[stIndex] == 'R'){
                 if(enIndex >= end.size() || end[enIndex] == 'L' || enIndex < stIndex){
                   return false;
               }
                enIndex++;
            }
            
            stIndex++;
        }
        
        // cout << stIndex << " " << enIndex << endl;
        
        return true;
    }
};