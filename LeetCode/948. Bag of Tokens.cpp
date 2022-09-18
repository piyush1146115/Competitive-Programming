class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        
        int score = 0, mxScore = 0;
        int p1 = 0, p2 = n - 1;
        
        while(p1 <= p2){
            if(power < tokens[p1] && score == 0)
                break;
            
            if(power >= tokens[p1]){
                power -= tokens[p1];
                p1++;
                score++;
            }
            else if(score > 0){
                power += tokens[p2];
                p2--;
                score--;;
            }
            
            mxScore = max(mxScore, score);
        }
        
        return mxScore;
    }
};