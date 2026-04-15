class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj)
     {
       int n = adj.size();     

      queue<pair<int,int>> q;
      vector<bool> visited(n,false);
      q.push({0,-1});
      visited[0] = true;

      while(!q.empty())
       {
        int r = q.front().first;
        int parent = q.front().second;

        q.pop();

        for(int c=0; c<n; c++)
         {
          if(c==parent) continue;
          if(adj[r][c]==1)
           {
            if(visited[c]==true) return true;
            q.push({c,r});
            visited[c] = true;
           }
         }
       }

       for(int i=0; i<n; i++)
         if(visited[i]==false) return true;
       
       return false;
     }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();

      vector<vector<int>> adj(n,vector<int>(n,0));

      for(int i=0; i<n; i++)
       {
        int u = edges[i][0]-1, v = edges[i][1]-1;

        adj[u][v] = 1;
        adj[v][u] = 1;
       }  

      for(int i=n-1; i>=0; i--)
       {
        int u = edges[i][0]-1, v = edges[i][1]-1;
        adj[u][v] = 0; adj[v][u] = 0;

        bool cycle = hasCycle(adj);

        if(!cycle) return {u+1,v+1};

        adj[u][v] = 1; adj[v][u] = 1;
       }

      return {};
    }
};