class Solution {
  public:
    int longestCommonSubsequence(string &s1, string &s2) {
      int size1 = s1.size();
      int size2 = s2.size();
      
      vector<vector<int>> dp(size1,vector<int>(size2,0));
      
      if(s1[0]==s2[0]) dp[0][0] = 1;
      
      for(int j=1; j<size2; j++)
       {
        if(s1[0]==s2[j]) 
            dp[0][j] = 1;
        else 
            dp[0][j] = dp[0][j-1];
       }
       
      for(int i=1; i<size1; i++)
       {
        if(s1[i]==s2[0]) 
            dp[i][0] = 1;
        else 
            dp[i][0] = dp[i-1][0];
       }
       
      for(int i=1; i<size1; i++)
       {
        for(int j=1; j<size2; j++)
         {
          if(s1[i]==s2[j])
            dp[i][j] = 1 + dp[i-1][j-1];
          else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
         }
       }
       
      return dp[size1-1][size2-1];
    }
};