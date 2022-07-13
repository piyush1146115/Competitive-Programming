class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long res = 0, j, k;
        int n = arr.size();
        stack<int> st;
        
        for(long i = 0; i <= arr.size(); i++){
            
            while(!st.empty() && arr[st.top()] > (i==n?-2e9:arr[i])){
                j = st.top();
                st.pop();
                
                k = (st.empty())?-1:st.top();
                
                res += (long)arr[j]*(i-j)*(j-k);
                res = res % 1000000007;
            }
            st.push(i);
        }
        
        return (int)res;
    }
};