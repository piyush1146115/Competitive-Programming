class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0, p = 0;
        int n = nums1.size(), m = nums2.size();
        
        int total = m + n;
        double sum = 0.0, temp;
        
        while(p1 < n || p2 < m){
         
            if(p2 == m || (p1 < n && nums1[p1] < nums2[p2])){
                temp = (double)nums1[p1];
                p1++;
                p++;
                
            }
            else{
                temp = (double)nums2[p2];
                p2++;
                p++;
            }
            
            if(total % 2 == 0){
                if(p == total/2 || p == total/2+1)
                    sum += temp;
            }
            else{
                if(p == total/2 + 1)
                    return temp;
            }
        }
        
        return sum/2.0;
    }
};