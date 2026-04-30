class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prev(m,vector<int>(k+1,-1e8)), curr(m,vector<int>(k+1,-1e8));
        for(int cost=0; cost<=k; cost++)
         {
          if(grid[0][0]==0) prev[0][cost] = curr[0][cost] = 0;
          else if(cost>0) prev[0][cost] = curr[0][cost] = grid[0][0]; 
         }

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            if(i==0 && j==0) continue;
            for(int cost=0; cost<=k; cost++)
             {
              int up = -1e8, left = -1e8;
              if(i>0)
               {
                if(grid[i][j]==0) up = prev[j][cost];
                else if(cost>0) up = grid[i][j] + prev[j][cost-1];
               }
              if(j>0)   
               {
                if(grid[i][j]==0) left = curr[j-1][cost];
                else if(cost>0) left = grid[i][j] + curr[j-1][cost-1];
               }
              curr[j][cost] = max(up,left);
             }
           }
          prev = curr;
         }

        if(prev[m-1][k]<0) return -1;
        return prev[m-1][k];
    }
};