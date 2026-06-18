class Solution {
public:
    bool doesMatch(string s, int i, string p, int j, vector<vector<int>>& dp)
     {
      if(i<=0 && j<=0) return true;
      if(j<=0) return false;

      if(i>0 && dp[i][j]!=-1) return dp[i][j];

      if(i>0 && (s[i-1]==p[j-1] || p[j-1]=='.'))
        return dp[i][j] = doesMatch(s,i-1,p,j-1,dp);

      if(p[j-1]=='*') 
       {
        int notTake = doesMatch(s,i,p,j-2,dp); //matching value before * with nothing
        int take = false;
        if(i>0 && (p[j-2]=='.' || p[j-2]==s[i-1])) take = doesMatch(s,i-1,p,j,dp)/*one match*/;

        return dp[i][j] = notTake | take;
       }
      return dp[i][j] = false;
     }

    bool isMatch(string s, string p) {
       int n = s.size(), m = p.size();

       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       bool matching = doesMatch(s,n,p,m,dp); 
       return matching;
    }
};