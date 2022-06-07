class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> Q;
        Q.push({0,1,0});
        
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            
            int pos = cur[0];
            int speed = cur[1];
            int steps = cur[2];
            
            
            if(pos == target){
                return steps;
            }
            
            if((pos+speed <= target*2) && (pos+speed)>0){
                Q.push({pos+speed, speed*2, steps+1});
            }
            if(speed > 0 && (pos+speed>target)){
                Q.push({pos, -1, steps+1});
            }
            if(speed <= 0 && (pos+speed < target)){
                Q.push({pos, 1, steps+1});
            }
            
        }
        
        return -1;
    }
};