class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;
        int cnt = 0, ans = 0;
        for ( auto &it: events) {
           cnt += it.second;
           ans = max (ans, cnt);
        }
        return ans;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
