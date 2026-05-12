class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
      {
        return (a[1] - a[0]) > (b[1] - b[0]);
      }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),comp);

        int totalEffort = tasks[0][1];
        int totalActual = tasks[0][0];

        int curr = totalEffort - totalActual;
        for(int i=1; i<n; i++)
         {
          int req = tasks[i][1] - curr;
          if(req>0) 
            totalEffort += req;

          totalActual += tasks[i][0];
          curr = totalEffort - totalActual;
         } 

        return totalEffort;
    }
};