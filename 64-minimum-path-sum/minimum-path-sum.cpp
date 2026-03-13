class Solution {
public:
    int minSum(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp)
     {
      if(m==0 && n==0) return dp[m][n] = grid[m][n];

      if(dp[m][n]!=-1) return dp[m][n];

      int up = INT_MAX, left = INT_MAX;
      if(m>0) up = grid[m][n] + minSum(grid,m-1,n,dp);
      if(n>0) left = grid[m][n] + minSum(grid,m,n-1,dp);
 
      return dp[m][n] = min(up,left);
     }

    int minPathSum(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       vector<int> prev(n,0);

       for(int i=0; i<m; i++) 
        {
         vector<int> curr(n,0);
         for(int j=0; j<n; j++)
          {
           if(i==0 && j==0)
             curr[0] = grid[i][j];
           else
            {
             int up = INT_MAX, left = INT_MAX;
             if(i>0) up = grid[i][j] + prev[j];
             if(j>0) left = grid[i][j] + curr[j-1];

             curr[j] = min(up,left);
            }
          }
         prev = curr;
        }

       return prev[n-1];
    }
};