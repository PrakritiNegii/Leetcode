class Solution {
public:
    bool isMatch(string s, string p) {
     int n = s.size(), m = p.size();

     vector<vector<int>> dp(n+1,vector<int>(m+1,false));

     dp[n][m] = true;

     for(int i=0; i<n; i++)
       dp[i][m] = false;

     for(int j=m-1; j>=0; j--)
      {
       if(p[j]!='*') break;
       dp[n][j] = true;
      }

     for(int i=n-1; i>=0; i--)
      {
       for(int j=m-1; j>=0; j--)
        {
         if(s[i]==p[j] || p[j]=='?') 
           dp[i][j] = dp[i+1][j+1];
         else if(p[j]=='*') 
               {
                bool notTake = dp[i][j+1]; //not taking any character to match(matching empty space)
                bool take = dp[i+1][j]; //taking the character

                dp[i][j] = take | notTake;
               }
              else
                dp[i][j] = false;
        }
      }

     return dp[0][0];   
    }
};