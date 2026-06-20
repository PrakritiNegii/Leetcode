class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1; i>=0; i--)
         {
          for(int bought=0; bought<=1; bought++)
           {
            for(int count=0; count<2; count++)
             {
              int take=0, notTake=0;
              if(!bought) // not bought then we can buy
               {
                take = -prices[i] + dp[i+1][true][count];
                notTake = dp[i+1][false][count];
               }
              else //bought then we sell
               {
                take = prices[i] + dp[i+1][false][count+1];  
                notTake = dp[i+1][true][count];  
               }
              dp[i][bought][count] = max(take,notTake);
             }
           }
         }
        return dp[0][false][0];
    }
};