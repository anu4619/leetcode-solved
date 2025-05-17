class MyCalendar {
public:
vector<pair<int, int>> bookings;
    MyCalendar() {
    
    }
    
    bool book(int startTime, int endTime) {
        for (const auto& booking : bookings) {
            int s = booking.first;
            int e = booking.second;
            if (startTime < e && s < endTime) {
    
                return false;
            }
        }
        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */