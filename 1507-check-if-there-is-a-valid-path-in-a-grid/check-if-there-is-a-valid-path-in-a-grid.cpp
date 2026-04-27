class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, char prev, vector<string>& directions)
     {
      if(i==0 && j==0) return true;

      int d = grid[i][j];
      string dir = directions[d];

      bool valid = false;
      for(int k=0; k<2; k++)
       {
        char ch = dir[k];
        if(prev=='U' && ch=='D') continue;
        if(prev=='D' && ch=='U') continue;
        if(prev=='L' && ch=='R') continue;
        if(prev=='R' && ch=='L') continue;

        if(ch=='L' && j>0 && !valid)
          {
           if(grid[i][j-1]==1 || grid[i][j-1]==4 || grid[i][j-1]==6)
              valid = isValid(grid,i,j-1,ch,directions);
          }
        else if(ch=='R' && j<grid[0].size()-1 && !valid)
               {
                if(grid[i][j+1]==1 || grid[i][j+1]==3 || grid[i][j+1]==5)
                   valid = isValid(grid,i,j+1,ch,directions);
               }
             else if(ch=='U' && i>0 && !valid)
                    {
                     if(grid[i-1][j]==2 || grid[i-1][j]==3 || grid[i-1][j]==4)
                        valid = isValid(grid,i-1,j,ch,directions);
                    }
                  else if(ch=='D' && i<grid.size()-1 && !valid)
                    {
                     if(grid[i+1][j]==2 || grid[i+1][j]==5 || grid[i+1][j]==6)
                        valid = isValid(grid,i+1,j,ch,directions);
                    }
       }
      return valid;
     }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<string> directions(7);
        directions[1] = "LR";
        directions[2] = "UD";
        directions[3] = "LD";
        directions[4] = "RD";
        directions[5] = "LU";
        directions[6] = "RU";

        return isValid(grid,n-1,m-1,' ',directions);
    }
};