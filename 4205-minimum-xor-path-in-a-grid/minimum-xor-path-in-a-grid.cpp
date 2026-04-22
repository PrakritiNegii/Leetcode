class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(1024,0))); 
        //range of xor values is taken as 1024 as the max value in grid can be 1023
        //The max no of 1s is 10 no xor can add extra 1

        for(int r=0; r<n; r++)
         {
          for(int c=0; c<m; c++)
           {
            for(int xorVal=0; xorVal<1024; xorVal++)
             {
              if(r==0 && c==0)
               {
                dp[0][0][xorVal] = xorVal ^ grid[0][0];
                continue;
               }
              int up = 1023, left = 1023;
              int currXor = xorVal ^ grid[r][c];

              if(r>0)
                up = dp[r-1][c][currXor];
              if(c>0)
                left = dp[r][c-1][currXor];

              dp[r][c][xorVal] = min(up,left);
             }
           }
         }
        
        return dp[n-1][m-1][0];
    }
};