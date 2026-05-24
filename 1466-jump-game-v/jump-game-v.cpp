class Solution {
public:
    int dfs(vector<int>& arr, int d, int idx, vector<int>& dp)
     {
        int n = arr.size();
        int maxIdx = 1;
        for(int k=idx+1; k<n && k<=idx+d; k++)
              {
               if(arr[k]>=arr[idx]) break;
               if(dp[k]!=0)
                {
                 maxIdx = max(maxIdx,1+dp[k]);
                 continue;
                }
               maxIdx = max(maxIdx, 1+dfs(arr,d,k,dp));
              }
        
        for(int k=idx-1; k>=0 && k>=idx-d; k--)
              {
               if(arr[k]>=arr[idx]) break;
               if(dp[k]!=0)
                {
                 maxIdx = max(maxIdx,1+dp[k]);
                 continue;
                }
               maxIdx = max(maxIdx, 1+dfs(arr,d,k,dp));
              }

        return dp[idx] = maxIdx;
     }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int maxVisits = 1;
        vector<int> dp(n,0);

        for(int i=0; i<n; i++)
         {
          maxVisits = max(maxVisits,dfs(arr,d,i,dp));
         }
        // vector<bool> visited(n,false);
        // vector<int> moves(n,0);
        // int maxIdx = 1;

        // for(int i=0; i<n; i++)
        //  {
        //   if(visited[i]==true) continue;
        //   queue<pair<int,int>> q;
        //   vector<bool> v(n,0);
        //   q.push({i,1});
        //   visited[i] = true;
        //   v[i] = true;

        //   int moves_i = 1;
        //   while(!q.empty())
        //    {
        //     int idx = q.front().first;
        //     int step = q.front().second;
        //     maxIdx = max(maxIdx,step);
        //     moves_i = max(moves_i,step);
        //     q.pop();

        //     for(int k=idx+1; k<n && k<=idx+d; k++)
        //       {
        //        if(arr[k]>=arr[idx]) break;
        //        if(v[k]==true) continue;
        //        visited[k] = true;
        //        v[k] = true;
        //        if(moves[k]!=0)
        //         {
        //          maxIdx = max(maxIdx,step+moves[k]);
        //          moves_i = max(moves_i, step + moves[k]);
        //          continue;
        //         }
        //        q.push({k,step+1});
        //       }

        //     for(int k=idx-1; k>=0 && k>=idx-d; k--)
        //       {
        //        if(arr[k]>=arr[idx]) break;
        //        if(v[k]==true) continue;
        //        visited[k] = true;
        //        v[k] = true;
        //        if(moves[k]!=0)
        //         {
        //          maxIdx = max(maxIdx,step+moves[k]);
        //          moves_i = max(moves_i, step + moves[k]);
        //          continue;
        //         }
        //        q.push({k,step+1});
        //       }
        //     }
        //    moves[i] = moves_i;
        //  }

        return maxVisits;
    }
};