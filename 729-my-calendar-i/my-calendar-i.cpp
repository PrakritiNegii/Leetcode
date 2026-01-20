class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int booked = 0;
        for(auto val : mp)
         {
          booked += val.second;
          if(booked>1) break;
         }
        
        if(booked<=1) return true;

        auto it = mp.find(startTime);
        if(it != mp.end()) {
          mp[startTime]--;
          if(mp[startTime]==0)
            mp.erase(it);  // deletes only one element
        }

        mp[endTime]++;
        if(mp[endTime] == 0) 
          mp.erase(endTime);  // deletes only one element
    
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */