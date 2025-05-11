// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<vector<char>> visited(rows,vector<char>(cols,'0'));
//         queue<pair<int,int>>q;
//         int c = 0;
//         for(int i=0; i<rows; i++)
//          {
//           for(int j=0; j<cols; j++)
//            {
//             if(visited[i][j]=='0' && grid[i][j]=='1')
//              {
//               c++;
//               q.push({i,j});
//               visited[i][j] = '1';
//               while(!q.empty())
//                {
//                 pair<int,int> temp = q.front();
//                 q.pop();
//                 int u = temp.first;
//                 int v = temp.second;

//                 if(v+1<cols && grid[u][v+1]=='1' && visited[u][v+1]!='1')
//                  {
//                   visited[u][v+1] = '1';
//                   q.push({u,v+1});
//                  }

//                 if(v-1>=0 && grid[u][v-1]=='1' && visited[u][v-1]!='1')
//                  {
//                   visited[u][v-1] = '1';
//                   q.push({u,v-1});
//                  }

//                 if(u+1<rows && grid[u+1][v]=='1' && visited[u+1][v]!='1')
//                  {
//                   visited[u+1][v] = '1';
//                   q.push({u+1,v});
//                  }

//                 if(u-1>=0 && grid[u-1][v]=='1' && visited[u-1][v]!='1')
//                  {
//                   visited[u-1][v] = '1';
//                   q.push({u-1,v});
//                  }
//                }
//              }
//            }
//          }
//         return c;
//     }
// };

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
       // vector<vector<char>> visited(rows,vector<char>(cols,'0'));
        queue<pair<int,int>>q;
        int c = 0;
        for(int i=0; i<rows; i++)
         {
          for(int j=0; j<cols; j++)
           {
            if(grid[i][j]=='1')
             {
              c++;
              q.push({i,j});
              grid[i][j] = 'v';
              while(!q.empty())
               {
                pair<int,int> temp = q.front();
                q.pop();
                int u = temp.first;
                int v = temp.second;
                int newR[] = {0,0,1,-1};
                int newC[] = {1,-1,0,0};

                for(int k=0; k<4; k++)
                 {
                  if(u+newR[k]<rows && u+newR[k]>=0 && v+newC[k]<cols && v+newC[k]>=0 && grid[u+newR[k]][v+newC[k]]=='1')
                   {
                    grid[u+newR[k]][v+newC[k]] = 'v';
                    q.push({u+newR[k],v+newC[k]});
                   }
                 }
               }
             }
           }
         }
        return c;
    }
};