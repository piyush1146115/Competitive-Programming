class MyStack {
public:
    queue<int> q1;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int sz = q1.size();
        
        while(sz > 1){
            sz--;
            int tp = q1.front();
            q1.pop();
            q1.push(tp);
        }
    }
    
    int pop() {
        int tp = q1.front();
        q1.pop();
        return tp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */