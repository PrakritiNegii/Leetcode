class Solution {
public:
    int partition(vector<int>& cuts, int i, int j, vector<bool> &visited, map<pair<int,int>,int>& dp)
     {
      if(i==j-1) return 0;

      if(dp.count({i,j})!=0) return dp[{i,j}];

      int minCost = INT_MAX;
      for(int c=0; c<cuts.size(); c++)
       {
        if(cuts[c]<i || cuts[c]>j) continue;

        int cost = INT_MAX;
        if(visited[c]==0)
         {
          visited[c] = 1;

          cost = (j-i) + partition(cuts,i,cuts[c],visited,dp) + partition(cuts,cuts[c],j,visited,dp);

          visited[c] = 0;
         }

        minCost = min(minCost,cost);
       }  
      if(minCost==INT_MAX) return dp[{i,j}] = 0;
      return dp[{i,j}] = minCost;
     }
    
    int minCost(int n, vector<int>& cuts) {
        int cutsSize = cuts.size();

        vector<bool> visited(cutsSize,0);
        map<pair<int,int>,int> dp;
        return partition(cuts,0,n,visited,dp);
    }
};