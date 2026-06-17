class Solution {
public:
    bool doesMatch(string s, int i, string p, int j, vector<vector<int>>& dp)
     {
      if(i<0 && j<0) return true;
      if(i<0) 
       {
        if(p[j]=='*')
         {
          while(j>=0)
           {
            if(p[j]!='*') return false;
            j-=2;
           }
         }
        else return false;
        return true;
       }
      if(j<0) return false;

      if(dp[i][j]!=-1) return dp[i][j];

      if(s[i]==p[j] || p[j]=='.')
        return dp[i][j] = doesMatch(s,i-1,p,j-1,dp);

      if(p[j]=='*') 
       {
        int notTake = doesMatch(s,i,p,j-2,dp); //matching value before * with nothing
        int take = false;
        if(p[j-1]=='.') take = doesMatch(s,i-1,p,j,dp)/*one match*/;
        else if(p[j-1]==s[i]) take = doesMatch(s,i-1,p,j,dp)/*one match*/;

        return dp[i][j] = notTake | take;
       }
      return dp[i][j] = false;
     }

    bool isMatch(string s, string p) {
       int n = s.size(), m = p.size();

       vector<vector<int>> dp(n,vector<int>(m,-1));
       bool matching = doesMatch(s,n-1,p,m-1,dp); 
       return matching;
    }
};