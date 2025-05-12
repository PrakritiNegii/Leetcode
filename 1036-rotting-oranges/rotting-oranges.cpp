class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int rCheck[] = {0,0,1,-1};
        int cCheck[] = {1,-1,0,0};
        int minutes = 0;
        queue <pair<int,int>> q;
        int c=0, cc=0;
        for(int i=0; i<rows; i++)
         {
          for(int j=0; j<cols; j++)
           {
            if(grid[i][j]==2)
             {
              q.push({i,j});
              cc++;
             }
           }
         }
         
        bool flag = false;

        while(!q.empty())
         {
           cout<<endl;
           int u = q.front().first;
           int v = q.front().second;
           q.pop();
           cc--;
           for(int k=0; k<4; k++)
            {
             int u_new = u + rCheck[k];
             int v_new = v + cCheck[k];
             if(u_new>=0 && u_new<rows && v_new>=0 && v_new<cols && grid[u_new][v_new]==1)
              {
               grid[u_new][v_new]=4;
               q.push({u_new,v_new});
               flag = true;
               c++;
              }
             }
            if(flag==true && cc==0) {minutes++; flag=false; cc=c; c=0;}
           }
                  
        for(int i=0; i<rows; i++)
         {
          for(int j=0; j<cols; j++)
           {
            if(grid[i][j]==1) return -1;
           }
         }
        return minutes;
    }
};