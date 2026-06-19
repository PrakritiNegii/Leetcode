class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> next(2,0), curr(2,0);

        for(int i=n-1; i>=0; i--)
         {
          for(int bought=0; bought<=1; bought++)
           {
            int take = 0, notTake = 0;
            if(!bought)
             {
              take = -prices[i] + next[true];
              notTake = next[false];
             }
            else 
             {
              take = prices[i] + next[false];
              notTake = next[true];
             }
            curr[bought] = max(take,notTake);
           }
          next = curr;
         }
        
        return next[false];
    }
};