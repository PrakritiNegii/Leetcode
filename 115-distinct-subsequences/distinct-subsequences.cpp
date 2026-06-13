class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();

        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0)); //shorter string for row

        for(int j=0; j<=m; j++)
          dp[0][j] = 1;

        for(int i=1; i<=n; i++)
         {
            for(int j=1; j<=m; j++)
              {
                unsigned long long take = 0;
                if(s[j-1]==t[i-1]) 
                   take = dp[i-1][j-1];
                
                unsigned long long notTake = dp[i][j-1];

                dp[i][j] = take + notTake;
              }
         }

        return (int) dp[n][m];
    }
};