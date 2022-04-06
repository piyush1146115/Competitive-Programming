class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int boat = 0;
        
        sort(people.begin(), people.end());
        
        int start = 0, en = people.size() - 1;
        
        while(start<=en){
            if(people[start] + people[en] <= limit){
                start++;
                en--;
            }else{
                en--;
            }
            boat++;
        }
        return boat;
    }
};