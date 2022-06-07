class DetectSquares {
public:
    map<pair<int,int>, int> ptsCount;
    vector<vector<int>> points;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[{point[0], point[1]}]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int ans = 0;
        
        for(auto p: points){
            int x = p[0];
            int y = p[1];
            
            if(abs(px-x)!=abs(py-y) || (x==px) || (y==py)){
                continue;
            }    
            ans += ptsCount[{x,py}]*ptsCount[{px,y}];
                
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */