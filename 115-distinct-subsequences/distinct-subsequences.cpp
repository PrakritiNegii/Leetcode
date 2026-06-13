class Solution {
public:
    long long distincts(string& s, int j, string& t, int i, vector<vector<long long>>& dp)
     {
      if(i==0) return 1;
      if(j==0) return 0;
      if(dp[i][j]!=-1) return dp[i][j];

      long long take=0, notTake=0;
      if(s[j-1]==t[i-1])
        take = distincts(s,j-1,t,i-1,dp);
      
      notTake = distincts(s,j-1,t,i,dp);

      return dp[i][j] = take + notTake;
     }

    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();

        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1)); //shorter string for row

        return (int) distincts(s,m,t,n,dp);
    }
};