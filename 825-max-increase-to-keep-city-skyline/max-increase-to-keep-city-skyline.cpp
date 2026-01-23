class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxCols(n);
        vector<int> maxRows(n);

        for(int i=0; i<n; i++)
         {
          int maxRow = grid[i][0];
          int maxCol = grid[0][i];
          for(int j=1; j<n; j++)
           {
            if(maxRow<grid[i][j]) maxRow = grid[i][j];
            if(maxCol<grid[j][i]) maxCol = grid[j][i];
           }
          maxCols[i] = maxCol;
          maxRows[i] = maxRow;
         }

        int maxHeightIncrease = 0;
        for(int i=0; i<n; i++)
         {
          for(int j=0; j<n; j++)
           {
            int skyline = min(maxRows[i],maxCols[j]);
            if(grid[i][j]<skyline) 
              maxHeightIncrease += (skyline-grid[i][j]);
           }
         }

        return maxHeightIncrease;
    }
};