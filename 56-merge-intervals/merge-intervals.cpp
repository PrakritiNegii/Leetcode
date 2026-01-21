class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();        
        
        map<int,int> mp;
        for(int i=0; i<n; i++)
         {
          int start = intervals[i][0];
          int end = intervals[i][1];
          mp[start]++;
          mp[end]--;
         }

        int newInterval = 0;
        bool st = true;
        vector<int> temp;
        for(auto val : mp)
         {
          if(newInterval==0 && val.second==0)
           {
            ans.push_back({val.first,val.first});
            continue;
           }
          newInterval += val.second;
          if(st==true) 
           {
            temp.push_back(val.first);
            st = false;
           }
          else if(newInterval==0) 
                {
                 temp.push_back(val.first);
                 ans.push_back(temp);
                 temp.clear();
                 st = true;
                }
         }
        return ans;
    }
};