class Solution {
  public:
    int lcsSize(string &s1, int i, string &s2, int j, vector<vector<int>>& dp) {
        if(i==0 && j==0)
         {
          if(s1[i]==s2[j]) return 1;
          return 0;
         }
         
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==0)
         {
          if(s1[i]==s2[j])
            return dp[0][j] = 1;
            /*
            s1 = "a"
            s2 = "aaaa"
            
            Ans = 1;
            
            However, return dp[i][0] = 1 + lcsSize(s1,i-1,s2,j,dp);
            returns 4;
            */
          else 
            return dp[0][j] = lcsSize(s1,i,s2,j-1,dp);
         }
        
        if(j==0)
         {
          if(s1[i]==s2[j])
            return dp[i][0] = 1;
          else 
            return dp[i][0] = lcsSize(s1,i-1,s2,j,dp);
         }
        
        int len = 0;
        if(s1[i]==s2[j])
          len = 1 + lcsSize(s1,i-1,s2,j-1,dp);
        else
         {
          len = max(len,lcsSize(s1,i-1,s2,j,dp));
          len = max(len,lcsSize(s1,i,s2,j-1,dp));
         }
        
        return dp[i][j] = len;
    }
  
    int longestCommonSubsequence(string &s1, string &s2) {
      int size1 = s1.size();
      int size2 = s2.size();
      
      vector<vector<int>> dp(size1,vector<int>(size2,-1));
      
      return lcsSize(s1,size1-1,s2,size2-1,dp);
    }
};