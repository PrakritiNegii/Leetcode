class Solution {
public:
    int triangleMinPath(vector<vector<int>> & triangle, int i, int j, vector<vector<int>>& dp)
     {
      if(i==0 && j==0) return triangle[i][j]; //reached peak (first element)
      if(dp[i][j]!=-1) return dp[i][j];

      int sameCol = INT_MAX, lesserCol = INT_MAX;

      if(j<triangle[i].size()-1)
       sameCol = triangle[i][j] + triangleMinPath(triangle,i-1,j,dp);

      if(j>0)
       lesserCol = triangle[i][j] + triangleMinPath(triangle,i-1,j-1,dp);

      return dp[i][j] = min(sameCol,lesserCol);
     }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int base = triangle[m-1].size();

        vector<vector<int>> dp(m,vector<int>(base,-1));

        int minPath = INT_MAX;
        for(int i=0; i<base; i++)
         {
          minPath = min(minPath,triangleMinPath(triangle,m-1,i,dp));
         }

        return minPath;
    }
};