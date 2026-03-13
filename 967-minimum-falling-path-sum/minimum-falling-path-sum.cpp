class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int j=0; j<n; j++)
         {
          dp[0][j] = matrix[0][j];
         }

        for(int i=1; i<m; i++)
         {
          for(int j=0; j<n; j++)
           {
            int below = INT_MAX, diagonalLeft = INT_MAX, diagonalRight = INT_MAX;

            below = matrix[i][j] + dp[i-1][j];
            if(j>0) 
              diagonalLeft = matrix[i][j] + dp[i-1][j-1];
            if(j<n-1) 
              diagonalRight = matrix[i][j] + dp[i-1][j+1];

            dp[i][j] = min({below,diagonalLeft,diagonalRight});
           }
         }

        int minP = INT_MAX;

        for(int j=0; j<n; j++)
         {
          minP = min(minP, dp[m-1][j]);
         }

        return minP;
    }
};