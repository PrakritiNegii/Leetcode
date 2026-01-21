class MyCalendar {
public:
    multiset<pair<int,int>> mst;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mst.insert({startTime,1});
        mst.insert({endTime,-1});

        int booked = 0;
        for(auto val : mst)
         {
          booked += val.second;
          if(booked>1) break;
         }
        
        if(booked==0) return true;

        auto it = mst.find({startTime,1});
        if(it != mst.end()) {
            mst.erase(it);  // deletes only one element
        }

        it = mst.find({endTime,-1});
        if(it != mst.end()) {
            mst.erase(it);  // deletes only one element
        }
    
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */