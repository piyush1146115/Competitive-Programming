class MyCalendar {
public:
    // vector<pair<int,int>> booking;
    set<pair<int,int>> booking;
    MyCalendar() {
        // booking.clear();    
    }
    
    bool book(int start, int end) {
//         for(auto it: booking){
//             if(it.first < end && start < it.second)
//                 return false;
//         }
        
//         booking.push_back({start,end});
//         return true;
        
        auto slot = booking.lower_bound({start,end});
        
        if(slot != booking.end() && (slot->first < end) ||
            (slot != booking.begin() && prev(slot)->second > start)){
            return false;
        }
        
        booking.insert({start,end});
        return true;
    }
    
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */