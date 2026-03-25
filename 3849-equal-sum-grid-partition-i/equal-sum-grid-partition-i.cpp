class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0LL, h = 0LL, v = 0LL;

        for(int i=0; i<grid.size(); i++)
         {
          for(int j=0; j<grid[0].size(); j++)
           {
            total += grid[i][j];
           }
         }

        if(total%2 != 0) return false; //impossible if odd 

        for(int i=0; i<grid.size(); i++)
         {
          for(int j=0; j<grid[0].size(); j++)
           {
            h += grid[i][j];
           }
          if(h==total/2) return true;
         }

        for(int j=0; j<grid[0].size(); j++)
         {
          for(int i=0; i<grid.size(); i++)
           {
            v += grid[i][j];
           }
          if(v==total/2) return true;
         }

        return false;
    }
};