class Solution {
public:
    bool hasCycle(vector<vector<char>>& grid, int si, int sj, vector<vector<char>>& visited)
     {
       int n = grid.size();
       int m = grid[0].size();

       char ch = grid[si][sj];
       queue<pair<pair<int,int>,pair<int,int>>> q;
       q.push({{si,sj},{-1,-1}});

       while(!q.empty())
        {
         int r = q.front().first.first;
         int c = q.front().first.second;
         int rParent = q.front().second.first;
         int cParent = q.front().second.second;

         q.pop();

         int rowD[] = {0,0,-1,1};
         int colD[] = {-1,1,0,0};

         for(int k=0; k<4; k++)
          {
           int newr = r + rowD[k];
           int newc = c + colD[k];

           if(newr==rParent && newc==cParent) 
              continue;

           if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==ch)
            {
             if(visited[newr][newc]=='0')
              {
                visited[newr][newc] = '1';
                q.push({{newr,newc},{r,c}});
              }
             else
                return true;
            }
          }
        }

       return false;
     }

    bool containsCycle(vector<vector<char>>& grid) {
       int n = grid.size();
       int m = grid[0].size();

       vector<vector<char>> visited(n,vector<char>(m,'0')) ;

       for(int i=0; i<n; i++)
        {
         for(int j=0; j<m; j++)
          {
           if(visited[i][j]=='0')
            {
             visited[i][j] = '1';
             if(hasCycle(grid,i,j,visited))
               return true;
            }
          }
        }

      return false;
    }
};