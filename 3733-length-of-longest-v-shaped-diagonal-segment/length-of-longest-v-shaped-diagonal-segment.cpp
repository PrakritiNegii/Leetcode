class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res = 0;
        int row[] = {1,1,-1,-1};
        int col[] = {1,-1,1,-1};
        for(int i=0; i<grid.size(); i++)
         {
          for(int j=0; j<grid[0].size(); j++)
           {
            if(grid[i][j]==1)
             {
              for(int ind=0; ind<4; ind++)
               {
                int len = lengthV(grid,i,j,row[ind],col[ind],false,2,1);
                if(len>res) res = len;
               }
             }
           }
         }
        return res;
    }

    int lengthV(vector<vector<int>>& grid, int r, int c, int cr, int cc, bool turn, int n, int len)
     {
      int newr = r+cr;
      int newc = c+cc;
      if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size())
       {
        if(grid[newr][newc]==n)
         {
          if(n==2) n=0;
          else n=2;
          int len0 = lengthV(grid,newr,newc,cr,cc,turn,n,len+1);
          int turnLen = 0;
          if(turn==false)
           {
            if(cr==cc) cc*=-1;
            else cr*=-1;
            turnLen = lengthV(grid,newr,newc,cr,cc,true,n,len+1);
            turn = true;
           }
          if(len0>turnLen) return len0;
          else return turnLen;
         }
        else return len;
        }
      else
        return len;
     } 
};