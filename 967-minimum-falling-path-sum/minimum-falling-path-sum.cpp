class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m,0);
        for(int j=0; j<m; j++)
         {
          prev[j] = matrix[0][j];
         }

        for(int i=1; i<n; i++)
         {
          vector<int> curr(m,0);
          for(int j=0; j<m; j++)
           {
            int below = INT_MAX, diagonalLeft = INT_MAX, diagonalRight = INT_MAX;

            below = matrix[i][j] + prev[j];
            if(j>0) 
              diagonalLeft = matrix[i][j] + prev[j-1];
            if(j<m-1) 
              diagonalRight = matrix[i][j] + prev[j+1];

            curr[j] = min({below,diagonalLeft,diagonalRight});
           }
          prev = curr;
         }

        int minP = INT_MAX;

        for(int j=0; j<m; j++)
         {
          minP = min(minP, prev[j]);
         }

        return minP;
    }
};