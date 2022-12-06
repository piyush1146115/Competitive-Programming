class Solution {
public:
    
     vector<int> root;
    vector<int> rank;
    void unionFind(int sz){
        for(int i = 0; i < sz ; i++){
            root[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int n){
        if(root[n] == n){
            return n;
        }
        
        return root[n] = find(root[n]);
    }
    
    void unionSet(int x, int y){
      //  cout << x << " " << y << endl;
        int rootX = find(x);
        int rootY = find(y);
        
        if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
        }
        else if(rank[rootY]>rank[rootX]){
            root[rootX] = rootY;
        }
        else{
            rank[rootX] += 1;
            root[rootY] = rootX;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        root = vector<int>(n + 1);
        rank = vector<int>(n + 1);
        
        unionFind(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    unionSet(i, j);
                }
            }
        }
        
        unordered_set<int> seen;
        int province_count = 0;
        
        
        for(int i = 0; i < n; i++){
            if(seen.find(find(i)) == seen.end()){
            //    cout << i << endl;
                province_count++;
            }
            //cout << find(i) << endl;
            seen.insert(find(i));
        }
        
        return province_count;
    }
};