class Solution {
public:
    int minXorCost(vector<vector<int>>& grid, int r, int c, int xorVal, vector<vector<vector<int>>>& dp)
     {
      if(r==0 && c==0)
        return xorVal ^ grid[0][0];
      if(dp[r][c][xorVal]!=-1) return dp[r][c][xorVal];

      int up = 1023, left = 1023;
      int currXor = xorVal ^ grid[r][c];

      if(r>0)
        up = minXorCost(grid,r-1,c,currXor,dp);
      if(c>0)
        left = minXorCost(grid,r,c-1,currXor,dp);

      return dp[r][c][xorVal] = min(up,left);      
     }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(1024,-1))); 
        //range of xor values is taken as 1024 as the max value in grid can be 1023
        //The max no of 1s is 10 no xor can add extra 1
        
        return minXorCost(grid,n-1,m-1,0,dp);
    }
};