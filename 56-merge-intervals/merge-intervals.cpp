class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int n = intervals.size();        
        vector<bool> M(n,false);
        

    for(int x=0; x<n; x++) 
     {
      int start = intervals[x][0];
      int finish = intervals[x][1];

      for(int i=x+1; i<n; i++)
        {
          bool merged = false;
          
          //no change to start and finish
          if(start<=intervals[i][0] && finish>=intervals[i][1])
            merged = true;

          //start is changed
          if(start>=intervals[i][0] && start<=intervals[i][1]) {
            start = intervals[i][0];
            merged = true;
          }
          
          //finish is changed
          if(finish>=intervals[i][0] && finish<=intervals[i][1])   {
            finish = intervals[i][1];
            merged = true;
           }
          
          if(merged==true)
           {
            intervals[i][0] = start;
            intervals[i][1] = finish;
            M[x] = true;
            break;
           }
         }
      }

      for(int i=0; i<n; i++)
       {
        if(M[i]==false) //didn't merge with any interval
          ans.push_back({intervals[i][0],intervals[i][1]});
       }
      return ans;
    }
};