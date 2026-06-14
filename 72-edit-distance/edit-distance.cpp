class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.size(), m = w2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++) //when j is 0
          dp[i][0] = i;        

        for(int j=1; j<=m; j++) //where i is 0
          dp[0][j] = j;

        for(int i=1; i<=n; i++)
         {
          for(int j=1; j<=m; j++)
           {
            if(w1[i-1]==w2[j-1]) 
              dp[i][j] = dp[i-1][j-1];
            else
             {
              int rem = 1 + dp[i-1][j];
              int ins = 1 + dp[i][j-1];
              int rep = 1 + dp[i-1][j-1];

              dp[i][j] = min({rem,ins,rep});
             }
           }
         }

        return dp[n][m];
    }
};