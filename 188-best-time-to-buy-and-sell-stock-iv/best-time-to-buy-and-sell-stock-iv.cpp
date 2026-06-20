class Solution {
public:
    int mProfit(vector<int>& prices, int i, bool bought, int k, vector<vector<vector<int>>>& dp)
     {
      if(i==prices.size() || k<0) return 0;

      if(dp[i][bought][k]!=-1) return dp[i][bought][k];

      int take=0, notTake=0;
      if(!bought)
       {
        take = -prices[i] + mProfit(prices,i+1,true,k,dp);
        notTake = mProfit(prices,i+1,false,k,dp);
       }
      else
       {
        take = prices[i] + mProfit(prices,i+1,false,k-1,dp);
        notTake = mProfit(prices,i+1,true,k,dp);
       }

      return dp[i][bought][k] = max(take,notTake);
     }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k,-1)));

        return mProfit(prices,0,false,k-1,dp);
    }
};