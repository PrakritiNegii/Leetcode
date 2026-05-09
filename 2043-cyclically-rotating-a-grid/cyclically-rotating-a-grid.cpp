class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> grid = matrix;
        int n = grid.size();
        int m = grid[0].size();

        int layers = min(n,m)/2;

        int row = 0, col =  0;
        int rowEnd = n-1, colEnd = m-1;

        while(layers>0)
         {
          int perimeter = (rowEnd-row)*2 + (colEnd-col)*2;
          int rot = k % perimeter; //total anticlockwise rotations
          rot = perimeter - rot; //total clockwise rotations

          int i=row, j=col;
          int val = grid[row][col];
          while(rot>0)
           {
            if(i==row && j==col)
             {
              while(j<colEnd)
               {
                int temp = grid[i][j+1];
                grid[i][j+1] = val;
                val = temp;
                j++;
               }
             }
            if(i==row && j==colEnd)
             {
              while(i<rowEnd)
               {
                int temp = grid[i+1][j];
                grid[i+1][j] = val;
                val = temp;
                i++;
               }
             }
            if(i==rowEnd && j==colEnd)
             {
              while(j>col)
               {
                int temp = grid[i][j-1];
                grid[i][j-1] = val;
                val = temp;
                j--;
               }
             }
            if(i==rowEnd && j==col)
             {
              while(i>row)
               {
                int temp = grid[i-1][j];
                grid[i-1][j] = val;
                val = temp;
                i--;
               }
             }
            val = grid[row][col];
            rot--;
           }

          row++; col++;
          rowEnd--; colEnd--;
          layers--;
         }
      return grid;
    }
};