class Solution {
public:
    int mProfit(vector<int>& prices, int i, int j, vector<vector<int>>& dp)
     {
      if(i==prices.size() || j==dp[0].size()) return 0;

      if(dp[i][j]!=-1) return dp[i][j];

      int take=0, notTake=0;
      if(j%2==0)
       {
        take = -prices[i] + mProfit(prices,i+1,j+1,dp);
        notTake = mProfit(prices,i+1,j,dp);
       }
      else
       {
        take = prices[i] + mProfit(prices,i+1,j+1,dp);
        notTake = mProfit(prices,i+1,j,dp);
       }

      return dp[i][j] = max(take,notTake);
     }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(k*2,-1));

        return mProfit(prices,0,0,dp);
    }
};