class Solution {
public:
    int mProfit(vector<int>& prices, int i, bool bought, vector<vector<int>> &dp)
     {
      if(i>=prices.size()) return 0;

      if(dp[i][bought]!=-1) return dp[i][bought];
      
      int take = 0, notTake = 0;
      if(!bought) // not bought then we can buy
       {
        take = -prices[i] + mProfit(prices,i+1,true,dp);
        notTake = mProfit(prices,i+1,false,dp);
       }
      else //bought then we sell
       {
        take = prices[i] + mProfit(prices,i+1,false,dp);  
        notTake = mProfit(prices,i+1,true,dp);  
       }
      
      return dp[i][bought] = max(take,notTake);
     }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return mProfit(prices,0,false,dp);
    }
};