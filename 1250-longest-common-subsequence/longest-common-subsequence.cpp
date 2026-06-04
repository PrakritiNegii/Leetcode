class Solution {
public:
    int lcsbstr(string &s1, string &s2, int i, int j, vector<vector<int>>& dp)
     {
      if(i==0 || j==0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      if(s1[i-1]==s2[j-1]) return dp[i][j] = 1+lcsbstr(s1,s2,i-1,j-1,dp);
      
      return dp[i][j] = max(lcsbstr(s1,s2,i-1,j,dp),lcsbstr(s1,s2,i,j-1,dp));
     }
     
    int longestCommonSubsequence(string s1, string s2) {
       int n1=s1.size(), n2=s2.size();
       vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

       for(int i=1; i<=n1; i++)
        {
         for(int j=1; j<=n2; j++)
          {
           if(s1[i-1]==s2[j-1]) 
              dp[i][j] = 1 + dp[i-1][j-1];
           else
            {
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
          }
        }     

       return dp[n1][n2]; 
    }
};