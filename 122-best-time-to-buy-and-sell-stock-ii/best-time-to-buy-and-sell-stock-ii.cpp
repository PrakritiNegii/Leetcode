class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1; i>=0; i--)
         {
          for(int bought=0; bought<=1; bought++)
           {
            int take = 0, notTake = 0;
            if(!bought)
             {
              take = -prices[i] + dp[i+1][true];
              notTake = dp[i+1][false];
             }
            else 
             {
              take = prices[i] + dp[i+1][false];
              notTake = dp[i+1][true];
             }
            dp[i][bought] = max(take,notTake);
           }
         }
        
        return dp[0][false];
    }
};