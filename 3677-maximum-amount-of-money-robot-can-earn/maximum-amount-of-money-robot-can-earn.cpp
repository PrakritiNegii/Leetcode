class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        
        for(int neutralize=0; neutralize<=2; neutralize++)
         {
          if(coins[0][0]<0 && neutralize>0) 
            dp[0][0][neutralize] = 0;
          else 
            dp[0][0][neutralize] = coins[0][0];
         }

        for(int i=0; i<n; i++)
         {
          for(int j=0; j<m; j++)
           {
            if(i==0 && j==0) continue;
            for(int neutralize=0; neutralize<=2; neutralize++)
             {
              int left = INT_MIN, top = INT_MIN;
              
              if((j-1)>=0) 
                left = coins[i][j] + dp[i][j-1][neutralize];
              if((i-1)>=0)
                top = coins[i][j] + dp[i-1][j][neutralize];

              if(coins[i][j]<0 && neutralize>0)
               {
                int leftN = INT_MIN, topN = INT_MIN;

                if((j-1)>=0) 
                   leftN = dp[i][j-1][neutralize-1];
                left = max(left,leftN);

                if((i-1)>=0) 
                   topN = dp[i-1][j][neutralize-1];
                top = max(top,topN);
               }
              
              dp[i][j][neutralize] = max(left,top);
             }
           }
         }

      return max({dp[n-1][m-1][0],dp[n-1][m-1][1],dp[n-1][m-1][2]});
    }
};