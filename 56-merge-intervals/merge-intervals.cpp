class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();        
        
        sort(intervals.begin(),intervals.end());
        for(int i=0; i<n;)
         {
          int start = intervals[i][0];
          int end = intervals[i][1];

          int j=i+1;
          for(; j<n; j++)
           {
            if(end>=intervals[j][0])
              end = max(end,intervals[j][1]);
            else 
              break;
           }

          ans.push_back({start,end});
          i = j;
         }

        return ans;
    }
};