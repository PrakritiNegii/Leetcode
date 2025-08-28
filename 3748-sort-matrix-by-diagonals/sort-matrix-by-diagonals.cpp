class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<char>> visited(n,vector<char>(n,'0'));
        for(int i=0; i<n; i++)
         {
          for(int j=0; j<n; j++)
            {
             char ch;
             if(i>=j) ch = 'd';
             else ch = 'a';
             if(visited[i][j]=='0' && (i+j)!=n-1)
               {
                visited[i][j] = '1';
                sortDiagonal(grid,visited,i,j,ch,n);
               }
            }
         }
        return grid;
    }

    void sortDiagonal(vector<vector<int>>& grid, vector<vector<char>>&visited, int r, int c, char ch, int n)
     {
      for(int i=r, j=c; i<n-1 && j<n-1; i++, j++)
       {
        int pass = 0;
        for(int ii=r, jj=c; ii<n-pass-1 && jj<n-pass-1; ii++, jj++)
         {
          if((ch=='d' && grid[ii][jj]<grid[ii+1][jj+1]) || (ch=='a' && grid[ii][jj]>grid[ii+1][jj+1]))
        //if((ii>=jj && grid[ii][jj]<grid[ii+1][jj+1]) || (ii<jj && grid[ii][jj]>grid[ii+1][jj+1]))
           {
            int temp = grid[ii][jj];
            grid[ii][jj] = grid[ii+1][jj+1];
            grid[ii+1][jj+1] = temp;
           }
          visited[ii+1][jj+1] = '1';
         }
       }
     }
};