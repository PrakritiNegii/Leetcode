class Solution {
public:
    int totalPaths(vector<vector<int>>& grid, int i, int j, int zeroes, int z, pair<int,int> end, vector<vector<bool>>& visited)
     {
      
      if(i==end.first && j==end.second)
       {
        if(z==zeroes) return 1;
        return 0;
       }

      int rowD[] = {-1,1,0,0};
      int colD[] = {0,0,-1,1};

      int paths = 0;
        for(int k=0; k<4; k++)
         {
          int newr = i + rowD[k];
          int newc = j + colD[k];

          if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && grid[newr][newc]!=-1 && visited[newr][newc]==false)
           {
            int newZ = z;
            if(grid[newr][newc]==0) newZ++;
            visited[newr][newc] = true;
            paths += totalPaths(grid, newr, newc, zeroes, newZ, end, visited);
            visited[newr][newc] = false;
           }
         }

      return paths;
     }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int zeroes = 0;
        pair<int,int> start;
        pair<int,int> end;

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            if(grid[i][j]==1) { start.first=i; start.second=j; }
            if(grid[i][j]==2) { end.first=i; end.second=j; }
            if(grid[i][j]==0) zeroes++;
           }
         }
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        visited[start.first][start.second] = true;
        return totalPaths(grid, start.first, start.second, zeroes, 0, end, visited);
    }
};