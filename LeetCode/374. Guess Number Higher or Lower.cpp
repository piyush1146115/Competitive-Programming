/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n, mid;
        
        while(lo <= hi){
            mid = (lo + hi)/2;
            
            int ret = guess(mid);
            
            if(ret == -1){
                hi = mid - 1;
            }
            else if(ret == 1){
                lo = mid + 1;
            }
            else{
                return mid;
            }
        }
        return mid;
    }
};