class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
     int rows = mat.size();
     int cols = mat[0].size();
     queue<pair<int,int>> q;
     vector<vector<int>> visited(rows,vector<int>(cols,0));
     for(int i=0; i<rows; i++)
      {
       for(int j=0; j<cols; j++)
        {
         if(!mat[i][j])
          {
           q.push({i,j});
           visited[i][j] = 1;
          }
        }
      }
         while(!q.empty())
          {
           int u = q.front().first;
           int v = q.front().second;
           q.pop();
           int rdir[] = {0,0,-1,1};
           int cdir[] = {-1,1,0,0};
           for(int i=0; i<4; i++)
            {
             int nu = u + rdir[i];
             int nv = v + cdir[i];
             if(nu>=0 && nu<rows && nv>=0 && nv<cols)
              {
               if(visited[nu][nv]==0)
                {
                 if(mat[nu][nv]!=0) 
                  mat[nu][nv] = mat[u][v] + 1;
                 
                 visited[nu][nv] = 1;
                 q.push({nu,nv});
                }
               else
                {
                 if(mat[u][v]+1 < mat[nu][nv])
                  {
                   mat[nu][nv] = mat[u][v] + 1;
                  }
                }
              }
            }
          }      
     return mat;
    }
};