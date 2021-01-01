class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> ans;
        
        if(nums1.size() < nums2.size()){
            for(int i = 0 ; i < nums2.size(); i++)
                st.insert(nums2[i]);
            
            for(int i = 0; i < nums1.size(); i++){
                if(st.find(nums1[i]) != st.end()){
                    ans.push_back(nums1[i]);
                    st.erase(nums1[i]);
                }
            }
        }
        else{
            for(int i = 0 ; i < nums1.size(); i++)
                st.insert(nums1[i]);
            
            for(int i = 0; i < nums2.size(); i++){
                if(st.find(nums2[i]) != st.end()){
                    ans.push_back(nums2[i]);
                    st.erase(nums2[i]);
                }
            }
        }
        
        return ans;
    }
};