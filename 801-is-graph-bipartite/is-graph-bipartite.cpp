class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int V = graph.size();
      vector<int> visited(V,0);
      for(int start=0; start<V; start++)
       {
        if(visited[start]!=0) continue;
        queue<int> q;
        visited [start] = 1;  //1 = Color 1, 2 = Color2
        q.push(start);
        while(!q.empty())
          {
            int n = q.front();
            q.pop();
            for(int i=0; i<graph[n].size(); i++)
             {
                 if(visited[graph[n][i]]==0)
                  {
                   if(visited[n]==1)
                     visited[graph[n][i]] = 2;
                   else
                     visited[graph[n][i]] = 1;
                   q.push(graph[n][i]);
                  }
                 else
                  {
                    if(visited[n]==visited[graph[n][i]])
                    return false;
                  }
             }
          }
       } 
      return true; 
    }
};