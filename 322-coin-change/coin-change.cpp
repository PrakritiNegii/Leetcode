class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n = coins.size();

        vector<int> prev(amount+1,1e8), curr(amount+1,1e8);
        prev[0] = 0;
        curr[0] = 0;

        for(int i=0; i<n; i++)
         {
          for(int amt=1; amt<=amount; amt++)
           {
            //not picking current coin
            int notPick = 1e8;
            if(i>0)
              notPick = prev[amt];

            //picking current coin 
            int pick = 1e8;
            if(amt>=coins[i])
             {
              int res = curr[amt-coins[i]];
              if(res != 1e8) pick = 1 + res;
             }

            curr[amt] = min(pick,notPick);
           }
          prev = curr;
         }

        if(prev[amount]==1e8) return -1;
        return prev[amount];
    }
};