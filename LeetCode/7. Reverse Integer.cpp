class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;
        
        while(x){
            int digit = x%10;
            x/=10;
            
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX%10))
                return 0;
            if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < INT_MIN%10))
                return 0;
            
            
            ans = (ans*10) + digit;
        }
        
        return ans;
    }
};