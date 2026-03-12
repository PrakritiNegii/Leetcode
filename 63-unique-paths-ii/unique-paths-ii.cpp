class Solution {
public:
    int totalUniquePaths(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp)
     {
      if(obstacleGrid[m][n]==1) return 0;

      if(m==0 && n==0) return 1;
      
      if(dp[m][n]!=-1) return dp[m][n];

      int top = 0, left = 0;
      if(m>0)
        top = totalUniquePaths(obstacleGrid,m-1,n,dp);
      if(n>0)
        left = totalUniquePaths(obstacleGrid,m,n-1,dp);
 
      return dp[m][n] = top+left;           
     }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return totalUniquePaths(obstacleGrid,m-1,n-1,dp);
    }
};