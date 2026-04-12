class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        for(int i=0; i<n; i++)
          dp[i][0] = 0;

        for(int i=0; i<n; i++)
         {
          for(int amt=1; amt<=amount; amt++)
           {
            //not picking current coin
            int notPick = 1e8;
            if(i>0)
              notPick = dp[i-1][amt];

            //picking current coin 
            int pick = 1e8;
            if(amt>=coins[i])
             {
              int res = dp[i][amt-coins[i]];
              if(res != 1e8) pick = 1 + res;
             }

            dp[i][amt] = min(pick,notPick);
           }
         }

        if(dp[n-1][amount]==1e8) return -1;
        return dp[n-1][amount];
    }
};