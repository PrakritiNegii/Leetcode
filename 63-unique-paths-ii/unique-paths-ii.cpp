class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0; i<m; i++)
         {
          for(int j=0; j<n; j++)
           {
            if(obstacleGrid[i][j]==1) 
             {
              obstacleGrid[i][j] = 0;
              continue;
             }
            if(i==0 && j==0) obstacleGrid[i][j] = 1;

            int newr = i-1;
            int newc = j-1;

            if(newr>=0) obstacleGrid[i][j] += obstacleGrid[newr][j];
            if(newc>=0) obstacleGrid[i][j] += obstacleGrid[i][newc];
           }
         }

        return obstacleGrid[m-1][n-1];
    }
};