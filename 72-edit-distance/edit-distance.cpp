class Solution {
public:
    int minChanges(string &w1, int i, string &w2, int j, vector<vector<int>>& dp)
     {
      if(i==0 && j==0) return 0;
      if(i==0) return j;
      if(j==0) return i;

      if(dp[i][j]!=-1) return dp[i][j];

      if(w1[i-1]==w2[j-1]) return dp[i][j] = minChanges(w1,i-1,w2,j-1,dp);
     
      int rem = 1 + minChanges(w1,i-1,w2,j,dp);
      int ins = 1 + minChanges(w1,i,w2,j-1,dp);
      int rep = 1 + minChanges(w1,i-1,w2,j-1,dp);

      return dp[i][j] = min({rem,ins,rep});
     }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return minChanges(word1,n,word2,m,dp);
    }
};