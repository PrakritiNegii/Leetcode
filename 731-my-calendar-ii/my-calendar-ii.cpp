class MyCalendarTwo {
public:
    vector<pair<int,int>> books;
    vector<pair<int,int>> overlaps;

    bool book(int start, int end) {
        // check triple booking
        for (auto &o : overlaps) {
            if (max(o.first, start) < min(o.second, end))
                return false;
        }

        // record new double bookings
        for (auto &b : books) {
            int s = max(b.first, start);
            int e = min(b.second, end);
            if (s < e)
                overlaps.push_back({s, e});
        }

        books.push_back({start, end});
        return true;
    }
};
