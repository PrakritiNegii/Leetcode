class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //shorter string for row

        int totali = 0;
        for(int j=1; j<=m; j++) //for row 1
          {
            if(t[0]==s[j-1])
              {
                dp[1][j] = 1; 
                totali += dp[1][j];
              }
          }

        for(int i=2; i<=n; i++)
         {
          char lasti = t[i-2];
          long long lastC = 0;
          for(int j=1; j<=m; j++)
           {
            if(t[i-1]==s[j-1]) 
                dp[i][j] = lastC;

            if(lasti==s[j-1])
                lastC += 1LL * dp[i-1][j];
           }
         }
         
        long long total = 0; //the sum of last row
        for(int j=1; j<=m; j++)
          total += 1LL * dp[n][j];

        return (int) total;
    }
};