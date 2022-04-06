class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        string l = to_string(low);
        string h = to_string(high);
        
        int low_size = l.size();
        int high_size = h.size();
        
        vector<int> ans;
        
        string str = "123456789";
        int n = 9;
        
        for(int i = low_size; i <= high_size; i++ ){
            for(int j = 0; j <= n - i; j++){
                string sub = str.substr(j, i);
                int temp = stoi(sub);
              //  cout <<i << " " << j << " " << temp << endl;
                if(temp >= low && temp <= high)
                    ans.push_back(temp);
            }        
        }
        
        
        return ans;
    }
};