class Solution {
public:
    int minChanges(string &w1, int i, string &w2, int j, vector<vector<int>>& dp)
     {
      if(i==w1.size() && j==w2.size()) return 0;
      if(i==w1.size()) return w2.size()-j;
      if(j==w2.size()) return w1.size()-i;

      if(dp[i][j]!=-1) return dp[i][j];

      int match = 1e8;
      if(w1[i]==w2[j]) return match = minChanges(w1,i+1,w2,j+1,dp);
     
      int rem = 1 + minChanges(w1,i+1,w2,j,dp);
      int ins = 1 + minChanges(w1,i,w2,j+1,dp);
      int rep = 1 + minChanges(w1,i+1,w2,j+1,dp);

      return dp[i][j] = min({match,rem,ins,rep});
     }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minChanges(word1,0,word2,0,dp);
    }
};