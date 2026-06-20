class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> next(2,vector<int>(3,0)), curr(2,vector<int>(3,0));

        for(int i=n-1; i>=0; i--)
         {
          for(int bought=0; bought<=1; bought++)
           {
            for(int count=0; count<2; count++)
             {
              int take=0, notTake=0;
              if(!bought) // not bought then we can buy
               {
                take = -prices[i] + next[true][count];
                notTake = next[false][count];
               }
              else //bought then we sell
               {
                take = prices[i] + next[false][count+1];  
                notTake = next[true][count];  
               }
              curr[bought][count] = max(take,notTake);
             }
           }
          next = curr;
         }
        return next[false][0];
    }
};