class Solution {
public:
    int totalUnique(int m, int n, vector<vector<int>>& dp)
     {
      if(n==0 && m==0) return 1;

      if(dp[m][n]!=-1) return dp[m][n];

      //Approach is top down starting from m-1, n-1
      int top=0, left=0;
      if(m>0)
        top = totalUnique(m-1,n,dp);
      if(n>0)
        left = totalUnique(m,n-1,dp);

      return dp[m][n] = top+left;
     }

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