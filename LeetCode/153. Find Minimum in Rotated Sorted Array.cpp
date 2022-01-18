class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]){
            return nums[0];
        }
        
        int lo = 0, hi = n -1, ans = 0;
        
        while(lo < hi){
            int mid = (lo+hi)/2;
          //  cout << mid << " " << nums[0] << " " << nums[n-1] << endl;
            if(mid + 1 < n && nums[mid] >= nums[mid + 1]){
                ans = mid +1;
            }
            if( mid - 1 >= 0 &&  nums[mid - 1] >= nums[mid]){
                ans = mid;
            }
            
            if(nums[mid] >= nums[0]){
                lo = mid + 1;
            }
            else{
                hi = mid -1;
            }
        }
        return nums[ans];
        
    }
};