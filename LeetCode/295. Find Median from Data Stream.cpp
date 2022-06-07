class MedianFinder {
public:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((minPQ.size()+maxPQ.size()) % 2 == 0)
            maxPQ.push(num);
        else
            minPQ.push(num);
        
        while(!minPQ.empty() && !maxPQ.empty() && maxPQ.top() > minPQ.top()){
            int mxtop = maxPQ.top();
            maxPQ.pop();
            int mntop = minPQ.top();
            minPQ.pop();
            
            minPQ.push(mxtop);
            maxPQ.push(mntop);
        }
            
    }
    
    double findMedian() {
        if(maxPQ.empty() && minPQ.empty())
            return 0.0;
        
        if((maxPQ.size()+minPQ.size()) % 2 == 0){
            double ret = (double)(maxPQ.top() + minPQ.top());
            ret = ret/2.0;
            return ret;
        }
        
        return (double)maxPQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */