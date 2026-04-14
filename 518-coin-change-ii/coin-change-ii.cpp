class Solution {
public:
    int allWays(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) 
     {
      if(amount==0) return 1;
      if(i<0) return 0;
      if(dp[i][amount]!=-1) return dp[i][amount];

      int notTake = allWays(coins,i-1,amount,dp);

      int take = 0;
      if(amount>=coins[i])
        take = allWays(coins,i,amount-coins[i],dp);

      return dp[i][amount] = notTake + take;
     }
    int change(int amount, vector<int>& coins) {
       int n = coins.size();

       vector<vector<int>> dp(n,vector<int>(amount+1,-1));
       return allWays(coins,n-1,amount,dp); 
    }
};