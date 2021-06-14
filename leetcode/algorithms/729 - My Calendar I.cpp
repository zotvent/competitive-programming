class MyCalendar {
    set<pair<int, int>> events;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = events.lower_bound({start, end});
        if (next != events.end() && next->first < end) return false;
        if (next != events.begin() && start < (--next)->second) return false;
        events.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */