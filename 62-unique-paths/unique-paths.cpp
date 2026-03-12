class Solution {
public: 
    int uniquePaths(int m, int n) {
         vector<vector<int>> dp(m,vector<int>(n,0));
         
         dp[0][0] = 1;

         for(int i=0; i<m; i++)
          {
           for(int j=0; j<n; j++)
            {
             //check can you reach this particular cell from the top or from the left
             int newr = i-1; //check top
             int newc = j-1; //check left

             if(newr>=0) dp[i][j] += dp[newr][j];
             if(newc>=0) dp[i][j] += dp[i][newc];
            }
           cout<<endl;
          }
         return dp[m-1][n-1];
    }
};