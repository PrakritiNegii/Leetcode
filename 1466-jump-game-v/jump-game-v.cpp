class Solution {
public:
    int dfs(vector<int>& arr, int d, int idx, vector<int>& dp)
     {
        if(dp[idx] != 0)
           return dp[idx];
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

        return maxVisits;
    }
};