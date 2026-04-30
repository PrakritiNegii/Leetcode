class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1e8)));
        for(int cost=0; cost<=k; cost++)
         {
          if(grid[0][0]==0) dp[0][0][cost] = 0;
          else if(cost>0) dp[0][0][cost] = grid[0][0]; 
         }

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            if(i==0 && j==0) continue;
            for(int cost=0; cost<=k; cost++)
             {
              int up = -1e8, left = -1e8;
              if(i>0)
               {
                if(grid[i][j]==0) up = dp[i-1][j][cost];
                else if(cost>0) up = grid[i][j] + dp[i-1][j][cost-1];
               }
              if(j>0)   
               {
                if(grid[i][j]==0) left = dp[i][j-1][cost];
                else if(cost>0) left = grid[i][j] + dp[i][j-1][cost-1];
               }
              dp[i][j][cost] = max(up,left);
             }
           }
         }

        if(dp[n-1][m-1][k]<0) return -1;
        return dp[n-1][m-1][k];
    }
};