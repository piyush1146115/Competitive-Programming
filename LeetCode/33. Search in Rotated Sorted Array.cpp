class Solution {
public:
    int search(vector<int>& nums, int target) {            
        int lo = 0, hi = nums.size() - 1, mid;
        int pivot = 0;
        
        if(nums.size() == 1)
            hi = -1;
        
        while(lo <= hi){
            mid = (lo + hi)/2;
          //   cout << mid << endl;
            
            if(mid + 1 < nums.size() && nums[mid] > nums[mid + 1]){
                pivot = mid + 1;
                break;
            }
            else{
                if(nums[mid] >= nums[lo]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        
        //cout << "Check"<< endl;
        
        
        if(nums[nums.size() - 1] >= target){
            lo = pivot;
            hi = nums.size() -1;
        }
        else{
            lo = 0;
            hi = pivot - 1;
        }

        
        int ans = -1;
        if(nums[pivot] == target)
            return pivot;
        
        //cout << "Check" << endl;
        
        while(lo <= hi){
            mid = (lo + hi)/2;
            
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};