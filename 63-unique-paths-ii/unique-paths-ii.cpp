class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n,0);

        for(int i=0; i<m; i++)
         {
          vector<int> curr(n,0);
          for(int j=0; j<n; j++)
           {
            if(obstacleGrid[i][j]==1) 
             {
              curr[j] = 0;
              continue;
             }
            if(i==0 && j==0) curr[j] = 1;

            int newr = i-1;
            int newc = j-1;

            if(newr>=0) curr[j] += prev[j];
            if(newc>=0) curr[j] += curr[j-1];
           }
          prev = curr;
         }

        return prev[n-1];
    }
};