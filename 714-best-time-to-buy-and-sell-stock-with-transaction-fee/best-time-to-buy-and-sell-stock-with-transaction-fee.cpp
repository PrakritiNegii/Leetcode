class Solution {
public:
    int mProfit(vector<int>& prices, int i, bool bought, int fee, vector<vector<int>>& dp)
     {
      if(i>=prices.size()) return 0;

      if(dp[i][bought]!=-1) return dp[i][bought];

      int take=0, notTake=0;
      if(!bought)
       {
        take = -prices[i] + mProfit(prices,i+1,true,fee,dp);
        notTake = mProfit(prices,i+1,false,fee,dp);
       }
      else
       {
        take = prices[i] - fee + mProfit(prices,i+1,false,fee,dp);
        notTake = mProfit(prices,i+1,true,fee,dp);
       }

       return dp[i][bought] = max(take,notTake);
     }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return mProfit(prices,0,false,fee,dp);
    }
};