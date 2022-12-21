class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> nextGreater;

        int n = nums2.size();
        nextGreater[nums2[n-1]] = -1;

        for(int i = n -2; i >= 0; i--){
            if(nums2[i] < nums2[i + 1]){
                nextGreater[nums2[i]] = nums2[i+1];
            }
            else{
                nextGreater[nums2[i]] = -1;
                int cur = nums2[i+1];
                while(nextGreater[cur] != -1){
                    cur = nextGreater[cur];
                    if(cur > nums2[i]){
                        nextGreater[nums2[i]] = cur;
                        break;
                    }
                }
            }
        }

        vector<int> ans;

        for(auto cur: nums1){
            ans.push_back(nextGreater[cur]);
        }

        return ans;
    }
};