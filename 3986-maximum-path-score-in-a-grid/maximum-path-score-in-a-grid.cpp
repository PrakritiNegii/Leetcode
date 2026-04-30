class Solution {
public:
    int maxScore(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp)
     {
      if(k<0) return -1e8;
      if(i==0 && j==0)
       {
        if(grid[0][0]==0) return 0;
        if(k>0) return grid[0][0];
        return -1e8;
       }
      if(dp[i][j][k]!=-1) return dp[i][j][k];

      int up = -1e8, left = -1e8;
      if(i>0)
       {
        if(grid[i][j]==0) up = maxScore(grid,i-1,j,k,dp);
        else up = grid[i][j] + maxScore(grid,i-1,j,k-1,dp);
       }
      if(j>0)
       {
        if(grid[i][j]==0) left = maxScore(grid,i,j-1,k,dp);
        else left = grid[i][j] + maxScore(grid,i,j-1,k-1,dp);
       }

      return dp[i][j][k] = max(up,left);
     }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int score = maxScore(grid,n-1,m-1,k,dp);

        if(score<0) return -1;
        return score;
    }
};