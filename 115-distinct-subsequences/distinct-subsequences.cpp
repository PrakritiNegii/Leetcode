class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();

        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0)); //shorter string for row

        for(int i=0; i<=n; i++)
          dp[i][0] = 1;

        for(int i=1; i<=n; i++)
         {
            for(int j=1; j<=m; j++)
              {
                unsigned long long take = 0;
                if(s[i-1]==t[j-1]) 
                   take = dp[i-1][j-1];
                
                unsigned long long notTake = dp[i-1][j];

                dp[i][j] = take + notTake;
              }
         }

        return (int) dp[n][m];
    }
};