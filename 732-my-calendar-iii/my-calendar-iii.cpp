class MyCalendarThree 
{
    int maxCount = 0;
    map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:    
    int book(int startTime, int endTime) 
     {
        mp[startTime]++;
        mp[endTime]--;
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
          {
            count += it->second;
            maxCount = max(count, maxCount);
          }
        return maxCount;   
     }
};