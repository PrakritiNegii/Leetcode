class Solution {
private:
 void bfs(vector<int>&visited, int start, vector<vector<int>>& isConnected)
     {
      visited[start] = 1;
      queue <int> q;
      q.push(start);
      while(!q.empty())
       {
        int n = q.front();
        q.pop();
        for(int i = 0; i<isConnected[n].size(); i++)
         {
          if(isConnected[n][i]==1 && visited[i]!=1)
           {
            visited[i] = 1;
            q.push(i);
           }
         }
       }
     }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> visited(size,0);
        int count = 0;
        for(int i=0; i<size; i++)
         {
          if(!visited[i])
           {
            count++;
            bfs(visited,i,isConnected);
           }
         }
      return count;
    }
};